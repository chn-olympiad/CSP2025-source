#include<bits/stdc++.h>
using namespace std;
int t, n, maxp;
int cnta, cntb, cntc;
int numa, numb, numc;

struct node{
	int a, b, c, i1, i2, i3, n1, n2, n3;
}mem[100005];

bool cmp(node a, node b)
{
	if(a.n1 == b.n1) {
		return a.n2 > b.n2;
	}
	return a.n1 > b.n1;
}

int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
	cin >> t;
	while(t--) {
		cin >> n;
		maxp = n / 2;
		cnta = cntb = cntc = numa = numb = numc = 0;
		for(int i = 1 ; i <= n ; i++) {
			cin >> mem[i].a >> mem[i].b >> mem[i].c;
			if(mem[i].a > mem[i].b) {
				mem[i].i1 = 1, mem[i].i2 = 2;
				mem[i].n1 = mem[i].a, mem[i].n2 = mem[i].b;
			}
			else {
				mem[i].i1 = 2, mem[i].i2 = 2;
				mem[i].n1 = mem[i].b, mem[i].n2 = mem[i].a;
			}
			
			if(mem[i].c > mem[i].n1) {
				mem[i].n3 = mem[i].n2, mem[i].n2 = mem[i].n1, mem[i].n1 = mem[i].c;
				mem[i].i3 = mem[i].i2, mem[i].i2 = mem[i].i1, mem[i].i1 = 3;
			}
			else if(mem[i].c > mem[i].n2) {
				mem[i].n3 = mem[i].n2, mem[i].n2 = mem[i].c;
				mem[i].i3 = mem[i].i2, mem[i].i2 = 3;
			}
			else mem[i].n3 = mem[i].c, mem[i].i3 = 3;
		}
		sort(mem + 1, mem + n + 1, cmp);
		for(int i = 1 ; i <= n ; i++) {
			if(mem[i].i1 == 1) {
				if(cnta >= maxp) {
					if(mem[i].i2 == 2) {
						cntb++;
						numb += mem[i].b;
					}
					else {
						cntc++;
						numc += mem[i].c;
					}
				}
				else {
					cnta++;
					numa += mem[i].a;
				}
			}
			else if(mem[i].i1 == 2) {
				if(cntb >= maxp) {
					if(mem[i].i2 == 1) {
						cnta++;
						numa += mem[i].a;
					}
					else {
						cntc++;
						numc += mem[i].c;
					}
				}
				else {
					cntb++;
					numb += mem[i].b;
				}
			}
			else {
				if(cntc >= maxp) {
					if(mem[i].i2 == 2) {
						cntb++;
						numb += mem[i].b;
					}
					else {
						cnta++;
						numa += mem[i].a;
					}
				}
				else {
					cntc++;
					numc += mem[i].c;
				}
			}
		}
		cout << numa + numb + numc << endl;
	}

}

