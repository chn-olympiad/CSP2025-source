#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct p{
	int a1,a2,a3;
	int x,y,z,k;
};
bool cmp(p a,p b){
	if(a.z==b.z){
			if(a.z==a.x && b.z==b.x) return a.y>b.y;
			else if(a.z==a.y && b.z==b.y)return a.x>b.x;
		}  
	else return a.z>b.z;
}
void s(){
	int n;
	cin>>n;
	p a[100001]={};
	ll sum=0;
	int cnt=0,num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
		sum+=a[i].a2;
		a[i].x=a[i].a1-a[i].a2;
		a[i].y=a[i].a3-a[i].a2;
		
		a[i].z=max(a[i].x,a[i].y);	
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		if(a[i].z<=0 && cnt+num>=n/2){
				break;
			}
		if(a[i].x==a[i].z && cnt<n/2){	
				cnt++;
				sum+=a[i].z;			
		}else if(a[i].y==a[i].z && num<n/2){
			num++;
			sum+=a[i].z;
		}
	}
	cout<<sum<<endl;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
	 s();
	}
	return 0;
}
