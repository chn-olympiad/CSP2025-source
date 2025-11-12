//GZ-S00369 贵阳市南明区华麟学校 罗翌宸 
#include<bits/stdc++.h>
using namespace std;
struct club{
	int fi;
	int se;
	int th;
};
int t,n;
club a[100000+10];

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int cnt1=0,cnt2=0,cnt3=0,sum=0,b,c,d;
		cin>>n;
		for(int i=1;i<=n;++i){
			cin>>a[i].fi>>a[i].se>>a[i].th;
		}
		int ma;
		for(int i=n;i>=1;--i){
			b=a[i].fi,c=a[i].se,d=a[i].th;
			int flag;
			if(b>c&&b>d)cnt1++,flag=1;
			else if(c>b&&c>d)cnt2++,flag=2;
			else if(d>b&&d>c)cnt3++,flag=3;
			if(cnt1>n/2){
				cnt1--;
				flag=0;
				if(c>d&&cnt2+1<=n/2)cnt2++,flag=2;
				else if(d>c&&cnt3+1<=n/2)cnt3++,flag=3;
			}
			else if(cnt2>n/2){
				cnt2--;
				flag=0;
				if(b>d&&cnt1+1<=n/2)cnt1++,flag=1;
				else if(d>b&&cnt3+1<=n/2)cnt3++,flag=3;
			}
			else if(cnt3>n/2){
				cnt3--;
				flag=0;
				if(b>c&&cnt1+1<=n/2)cnt1++,flag=1;
				else if(c>b&&cnt2+1<=n/2)cnt2++,flag=2;
			}
			if(flag==1)sum+=b;
			else if(flag==2)sum+=c;
			else if(flag==3)sum+=d;
		}
		cout<<sum<<endl;
	}
	return 0;
}
