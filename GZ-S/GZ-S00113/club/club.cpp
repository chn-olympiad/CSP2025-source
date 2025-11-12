//GZ-S00113 黎平县第二中学 唐启谦 
#include<iostream>
#include<algorithm>
using namespace std;
struct stu{
	int a[3],ta=-1;
}s[100000];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n,ans;
	cin>>t;
	while(t--){
		ans=0;
		cin>>n;
		for(int i=0;i<n;i++)cin>>s[i].a[0]>>s[i].a[1]>>s[i].a[2];
		sort(s,s+n,[](stu a,stu b){return a.a[0]!=b.a[0]?a.a[0]>b.a[0]:a.a[1]<b.a[1];});
		for(int i=0;i<n/2;i++)s[i].ta=0;
		sort(s,s+n,[](stu a,stu b){return a.a[1]!=b.a[1]?a.a[1]>b.a[1]:a.ta<b.ta;});
		int lim=n/2;
		for(int i=0;i<lim;i++){
			if(s[i].ta==-1)s[i].ta=1;
			else{
				if(s[i].a[s[i].ta]<s[i].a[1])s[i].ta=1;
				else{
					lim++;
					if(lim>=n)break;
				}
			}
		}sort(s,s+n,[](stu a,stu b){return a.a[2]>b.a[2];});
		lim=n/2;
		for(int i=0;i<lim;i++){
			if(s[i].ta==-1)s[i].ta=2;
			else{
				if(s[i].a[s[i].ta]<s[i].a[2])s[i].ta=2;
				else{
					lim++;
					if(lim>=n)break;
				}
			}
		}for(int i=0;i<n;i++)ans+=s[i].a[s[i].ta];
		cout<<ans<<endl;
	}return 0;
}
//CCF I hate you.
