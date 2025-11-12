#include<bits/stdc++.h>
using namespace std;
int t,n,x,y,z,f,g,h;
int ss(int a,int b,int c){
	if((a>b&&a<c)||(a<b&&a>c)){
		return a;
	}else if((b>a&&b<c)||(b<a&&b>c)){
		return b;
	}else{
		return c;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		int m=n/2,ans=0;
		vector<int> a,b,c;
		x=0,y=0,z=0;
		for(int i=1;i<=n;i++){
			cin>>f>>g>>h;
			int s=max(max(f,g),h)-ss(f,g,h);
			if(f>g&&f>h)x++,a.push_back(s);
			else if(g>f&&g>h)y++,b.push_back(s);
			else z++,c.push_back(s);
			ans+=max(max(f,g),h);
		}
		if(x>m){
			sort(a.begin(),a.end());
			for(int i=0;i<x-m;i++){
				ans-=a[i];
			}
		}else if(y>m){
			sort(b.begin(),b.end());
			for(int i=0;i<y-m;i++){
				ans-=b[i];
			}
		}else{
			sort(c.begin(),c.end());
			for(int i=0;i<z-m;i++){
				ans-=c[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
//4 4 2 1 3 2 4 5 3 4 3 5 1      18
//4 0 1 0 0 1 0 0 2 0 0 2 0      4
//2 10 9 8 4 0 0                 13
