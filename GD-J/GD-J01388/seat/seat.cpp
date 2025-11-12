#include<bits/stdc++.h>
using namespace std;
struct node{
	int x,w;
}s[110];
int n,m,t,f;
bool cmp(node n1,node n2){
	return n1.x>n2.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>s[i].x;
		s[i].w=i;
	}
	sort(s+1,s+1+n*m,cmp); 
	for(int i=1;i<=m;i++){
		f=1-f;
		if(f)
		    for(int j=1;j<=n;j++){
		        t++;
		    	if(s[t].w==1){
		    	    cout<<i<<" "<<j;
		    	    return 0;
			    }
			}
		else
		    for(int j=n;j>=1;j--){
		    	t++;
		    	if(s[t].w==1){
		    	    cout<<i<<" "<<j;
		    	    return 0;
			    }
			}
	}
	return 0;
} 
