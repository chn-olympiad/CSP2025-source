#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m,r=0,zw=1,cnt=0;
	vector<int> st;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		int a;
		cin>>a;
		st.push_back(a);
		if(i==0){
		   r=a;	
		}
	}
	for(int i=0;i<st.size();i++){
		for(int j=i;j>=1;j--){
			if(st[j]>st[j-1]){
				int t=st[j-1];
				st[j-1]=st[j];
				st[j]=t;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
		    if(st[(i-1)*n+(j-1)]==r){
		    	int l=0,h=0;
		    	if(i%2==0){
		    		l=i;
		    		h=n-j+1;
		    		if(h==0){
		    			h=1;
					}
				}else{
					l=i;
					h=j;
					if(h==0){
						h=n;
					}
				}
				cout<<l<<" "<<h;
				break;
			}
		}
	}
	return 0;
}
