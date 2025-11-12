#include<bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;
int n,t,s,s1,s2,s3;
struct k{
	int a1;
	int a2;
	int a3;
}a[MAX];

void Sort1(int x,int y ,int z,int i)
{
	if(y / 10 < z / 10) swap(y,z);
	if(x / 10 < y / 10) swap(x,y);
	a[i].a1 = x;
	a[i].a2 = y;
	a[i].a3 = z;
}

void Sort2()
{
	for(int i = 1;i <= n; i++)
	{
		for(int j = 2; j <= n; j++)
		{
			if(a[j].a1/10 < a[j-1].a1/10) swap(a[j], a[j - 1]);
			else if(a[j].a1/10 == a[j-1].a1/10){if(a[j].a2/10 < a[j-1].a2/10) swap(a[j], a[j - 1]);else if(a[j].a2/10 == a[j-1].a2/10){if(a[j].a3/10 < a[j-1].a3/10) swap(a[j], a[j - 1]);}
		}
	}
}
}
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >> t;
	while(t)
	{
		cin >> n;
		for(int i = 1; i <= n; i ++)
		{
			cin >> a[i].a1;
			cin >> a[i].a2;
			cin >> a[i].a3;
			if(a[i].a1 != 0) a[i].a1 = a[i].a1 * 10 + 1;
			if(a[i].a2 != 0) a[i].a2 = a[i].a2 * 10 + 2;
			if(a[i].a3 != 0) a[i].a3 = a[i].a3 * 10 + 3;
			Sort1(a[i].a1, a[i].a2, a[i].a3, i);
		}
		Sort2;
		for(int i = 1; i <= n; i++)
		{
			int k1=a[i].a1%10;
			int k2=a[i].a2%10;
			int k3=a[i].a3%10;
			if(k1 == 1){
				if(s1 < n/2){
					s+=(a[i].a1/10);
					s1++;
				}else{
				if(k2 == 2){
					if(s2 < n/2){
						s+=(a[i].a2/10);
						s2++;
					}
					else{
						s3++;
						s+=(a[i].a3/10);
					}
				}
				if(k2== 3){
					if(s2 < n/2){
						s+=(a[i].a2/10);
						s2++;
					}else{
						s2++;
						s+=(a[i].a3/10);
					}
				}
				}
			}
			if(k1 == 2){
				if(s2 < n/2){
					s+=(a[i].a1/10);
					s2++;
				}else{
				if(k2 == 1){
					if(s1 < n/2){
						s+=(a[i].a2/10);
						s1++;
					}
					else{
						s3++;
						s+=(a[i].a3/10);
					}
				}
				if(k2 == 3){
					if(s1 < n/2){
						s+=(a[i].a2/10);
						s1++;
					}else{
						s1++;
						s+=(a[i].a3/10);
					}
				}
				}
			}
			if(k1 == 3){
				if(s3 < n/2){
					s+=(a[i].a1/10);
					s3++;
				}else{
				if(k2 == 1){
					if(s1 < n/2){
						s+=(a[i].a2/10);
						s1++;
					}
					else{
						s2++;
						s+=(a[i].a3/10);
					}
				}
				if(k2 == 2){
					if(s1 < n/2){
						s+=(a[i].a2/10);
						s2++;
					}else{
						s1++;
						s+=(a[i].a3/10);
					}
				}
				}
			}
		}
		cout<<s<<endl;
		s = 0;
		s1 = 0;
		s2 = 0;
		s3 = 0;
		t--;
	}
	return 0;
}
