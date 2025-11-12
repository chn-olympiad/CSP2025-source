#include<bits/stdc++.h>
using namespace std;
int n,m,a[501],ans=0;
string s;
void solve(int num,int h,int y,int c){
    //cout<<n<<" "<<h<<" "<<y<<" "<<c<<endl;
	if(num==0){
		if(y>=m){
		    ans+=1;
		    //cout<<"+1"<<endl;
	    }
		return;
	}
	for(int i=h;i<n;i++){
		if(c>=a[i]) continue;
		else{
			if(s[h]=='1') {
			    solve(num-1,h+1,y+1,c);
		    }
			else{
			    solve(num-1,h+1,y,c+1);
			}
		}
	}
	
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	cin>>n>>m>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	solve(n,0,0,0);
	cout<<ans+1;
	return 0;
}
