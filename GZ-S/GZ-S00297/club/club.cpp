//GZ-S00297 毕节七星关东辰实验学校 洪崇昊
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10; 
int t;
struct stu{
	int want,c;
};
bool cmp(stu a,stu b){
	return a.c<b.c;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n;
		stu a[N];
		long long ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			int f=0;
			int s=0;
			for(int j=1;j<=3;j++){
				int num;
				scanf("%d",&num);
				if(num>f){
					s=f;
					f=num;
					a[i].want=j;
				}
				else{
					s=max(s,num);
				}
			}
			a[i].c=f-s;
			ans+=s;
		}
		sort(a+1,a+n+1,cmp);
		int rest[4]={0,0,0,0};
		for(int i=n;i>0;i--){
			if(rest[a[i].want]<n/2){
				ans+=a[i].c;
				rest[a[i].want]++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
