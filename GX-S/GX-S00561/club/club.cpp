#include<bits/stdc++.h>
using namespace std;
struct stu{
	int x,y,z,st1,st2,st3;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		stu a[100005];
		long long sum=0,ss=0,s1=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].x>>a[i].y>>a[i].z;
			if(a[i].y==0)ss++;
			if(a[i].z==0)s1++;
		}
		if(ss==n&&s1==n){
			int h=n/2;
			while(h--){
				int maxx=-114;
				for(int i=1;i<=n;i++)if(a[i].x>maxx)maxx=a[i].x;
				sum+=maxx;}}
		cout<<sum<<endl;
		return 0;
	}
	return 0;
}
