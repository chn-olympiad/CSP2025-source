#include<bits/stdc++.h>
using namespace std;
const int N = 100010;
struct people{
	long long a,b,c;
}p[N];
long long  n,t;
long long f(long long now,long long num,long long a,long long b,long long c){
	
	if(now > n){
//		cout<<"ing"<<now<<" "<<num<<" "<<a<<" "<<b<<" "<<c<<endl;
		return num;
	}
	long long ans=0;
	if(a == n/2){
		if(p[now] . b >= p[now].c){
			ans = max(ans,f(now+1,num + p[now].b,a,1+b,c));
		}else{
			ans = max(ans,f(now+1,num + p[now].c,a,b,1+c));
		}
	}else{
		ans = max(ans,f(now+1,num + p[now].a,a+1,b,c));
		if(b == n/2){
			if(p[now] . a >= p[now].c){
				ans = max(ans,f(now+1,num + p[now].a,1+a,b,c));
			}else{
				ans = max(ans,f(now+1,num + p[now].c,a,b,1+c));
			}
		}else{
			ans = max(ans,f(now+1,num + p[now].b,a,b+1,c));
			
			if(c == n/2){
				if(p[now] . a >= p[now].b){
					ans = max(ans,f(now+1,num + p[now].a,1+a,b,c));
				}else{
					ans = max(ans,f(now+1,num + p[now].b,a,1+b,c));
				}
			}else{
				ans = max(ans,f(now+1,num + p[now].c,a,b,c+1));
			}
		}
	}
	
	
	
	return ans;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i = 1; i <= n;i++){
			cin>>p[i].a>>p[i].b>>p[i].c;
		}
//		cout<<endl<<"***"<<"OK"<<"***"<<endl<<endl;
		cout<<f(1,0,0,0,0)<<endl;
	}
	return 0;
}
