#include<bits/stdc++.h>
using namespace std;
struct people{
	int a, b, c;
	int pass, much;
}hap[100001];
bool cmp(people x, people y){
	return x.much > y.much;
}
int main(){
	freopen("club.in", "r", stdin);
	freopen("clud.out", "w", stdout);
	int t;
	cin >> t;
	while(t--){
		int n, sum = 0;
		cin >> n;
		int oa = n/2, ob = n/2, oc = n/2;
		for(int i = 1; i <= n; i++){
			cin >> hap[i].a >> hap[i].b >> hap[i].c;
			hap[i].much = max(hap[i].a, max(hap[i].b, hap[i].c));
			if(hap[i].much == hap[i].a) hap[i].pass = 1;
			else if(hap[i].much == hap[i].b) hap[i].pass = 2;
			else hap[i].pass = 3;
		}
		sort(hap+1,hap+n+1, cmp);
		for(int i = 1; i<= n; i++){
			if(hap[i].pass == 1 && oa != 0)oa--;
			else if(hap[i].pass == 2 && ob != 0)ob--;
			else if(hap[i].pass == 3 && oc != 0)oc--;
			else if(oa == 0 && hap[i].pass == 1){
				hap[i].much = hap[i].b > hap[i].c ? hap[i].b : hap[i].c;
			}
			else if(ob == 0 && hap[i].pass == 2){
				hap[i].much = hap[i].a > hap[i].c ? hap[i].a : hap[i].c;
			}
			else if(oc == 0 && hap[i].pass == 3){
				hap[i].much = hap[i].a > hap[i].b ? hap[i].a : hap[i].b;
			}
			sum += hap[i].much;
		}
		cout << sum << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
