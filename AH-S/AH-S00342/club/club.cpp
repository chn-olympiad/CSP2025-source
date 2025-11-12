#include <bits/stdc++.h>
#define int long long
using namespace std;
int sizes[5];
void solve(){
	sizes[1]=sizes[2]=sizes[3]=0;
	int n;cin>>n;
    int sum=0;
    priority_queue<int,vector<int>,greater<int>> q1;
		priority_queue<int,vector<int>,greater<int>> q2;
		priority_queue<int,vector<int>,greater<int>> q3;
    
    for(int i=1;i<=n;i++){
       int a,b,c; 
		
        if(a>=b&&a>=c){
            int x=a-max(b,c);q1.push(x);
            sizes[1]++;
            sum+=a;
        }
        else if(b>=a&&b>=c){
            int x=b-max(a,c);q2.push(x);
            sum+=b;
            sizes[2]++;
        }
        else{
            int x=c-max(a,b);q3.push(x);
            sum+=c;
            sizes[3]++;
        }
    }
    if(sizes[1]>n/2){
        
        while(sizes[1]>n/2) sum-=q1.top(),q1.pop(),sizes[1]--;
    }
    if(sizes[2]>n/2){
        
        while(sizes[2]>n/2) sum-=q2.top(),q2.pop(),sizes[2]--;
    }
    
    if(sizes[3]>n/2){
        while(sizes[3]>n/2) sum-=q3.top(),q3.pop(),sizes[3]--;
    }
    

	cout<<sum;
	return;
}
signed main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;cin>>T;
    while(T--){
	solve();
	cout<<'\n';
	}
	//cout<<"end";
    return 0;
}



