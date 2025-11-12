#include <bits/stdc++.h>
using namespace std;

struct Edge{
	int x1,x2,x3;
	bool cmp = false;
}a[20005];

int b[10];
int main()
{
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int T;cin>>T;
	for(int c = 1;c<=T;c++){
		int n;cin>>n;
		for(int i = 1;i<=n;i++){
			cin>>a[i].x1>>a[i].x2>>a[i].x3;
		}
		for(int i = 1;i<=n;i++){
			int cnt1 = 0,cnt2 = 0,cnt3 = 0;
			int cmp2 = max(a[i].x1,max(a[i].x2,a[i].x3));
			int cmp1 = max(a[i].x2,a[i].x3);
			if(a[i].x1>a[i].x2&&cnt2+1<=n/2&&a[i].x1>a[i].x3&&cnt3+1<=n/2&&cnt1+1<=n/2&&a[i].cmp == false){
				b[c]+=a[i].x1;
				cnt1++;
				a[i].cmp = true;
			}else if(a[i].x2>a[i].x1&&cnt3+1<=n/2&&a[i].x2>a[i].x3&&cnt1+1<=n/2&&cnt2+1<=n/2&&a[i].cmp == false){
				b[c]+=a[i].x2;
				cnt2++;
				a[i].cmp = true;
			}else if(a[i].x3>a[i].x1&&cnt2+1<=n/2&&a[i].x3>a[i].x2&&cnt1+1<=n/2&&cnt3+1<=n/2&&a[i].cmp == false){
				b[c]+=a[i].x3;
				cnt3++;
				a[i].cmp = true;
			}else if(cmp1 == a[i].x1&&cnt2+1<=n/2&&cnt3+1<=n/2&&cnt1+1<=n/2&&a[i].cmp == false){
				b[c]+=a[i].x1;
				cnt1++;
				a[i].cmp = true;
			}else if(cmp1 == a[i].x2&&cnt3+1<=n/2&&cnt1+1<=n/2&&cnt2+1<=n/2&&a[i].cmp == false){
				b[c]+=a[i].x2;
				cnt2++;
				a[i].cmp = true;
			}else if(cmp1 == a[i].x3&&cnt2+1<=n/2&&cnt1+1<=n/2&&cnt3+1<=n/2&&a[i].cmp == false){
				b[c]+=a[i].x3;
				cnt3++;
				a[i].cmp = true;
			}else if(cmp2 == a[i].x2&&cnt3+1<=n/2&&cnt1+1<=n/2&&cnt2+1<=n/2&&a[i].cmp == false){
				b[c]+=a[i].x2;
				cnt2++;
				a[i].cmp = true;
			}else if(cmp2 == a[i].x3&&cnt2+1<=n/2&&cnt1+1<=n/2&&cnt3+1<=n/2&&a[i].cmp == false){
				b[c]+=a[i].x3;
				cnt3++;
				a[i].cmp = true;
			}else if(cnt3+1<=n/2&&cnt2+1<=n/2&&cnt1<n/2&&a[i].cmp == false){
				b[c]+=a[i].x1;
				cnt1++;
				a[i].cmp = true;
			}
		}
	}
	for(int i = 1;i<=T;i++){
		cout<<b[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
}

