#include<bits/stdc++.h>
using namespace std;
long long n;
long long ans=0;
struct node{
	long long x,y,z;
}stu[200000];
void qwe(long long a,long long b,long long c,long long d,long long e){

	if(a==n+1){
		if(b<=n/2&&c<=n/2&&d<=n/2){
			ans=max(ans,e);

		}return;

	}if(b>n/2||c>n/2||d>n/2)return;
	int p=0;
     if(stu[a].x!=0){
     	p++;
	qwe(a+1,b+1,c,d,e+stu[a].z);
     } if(stu[a].y!=0){
     	p++;
	qwe(a+1,b,c+1,d,e+stu[a].y);
     } if(stu[a].z!=0){
     	p++;
	qwe(a+1,b,c,d+1,e+stu[a].x);
     }if(p==0){
     	qwe(a+1,b,c+1,d,e+stu[a].y);
	 }
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	long long g;
	cin>>g;
	for(int f=1;f<=g;f++){
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>stu[i].x>>stu[i].y>>stu[i].z;
		}qwe(1,0,0,0,0);
		cout<<ans<<endl;

	}fclose(stdin);
	fclose(stdout);
	return 0;
}
