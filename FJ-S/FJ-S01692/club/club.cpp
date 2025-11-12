#include<bits/stdc++.h>
using namespace std;
int a[4][114514],su[114514],b,c,d;
priority_queue <int> q;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;int n;
	cin>>t;
	while(t!=0){
		int o=0;
		cin>>n;int p[4];
		while(!q.empty()){
			q.pop();
		}
		for(int i=0;i<=2;i++){
			p[i]=0;
		}
		int w=0;
		for(int i=1;i<=n;i++){
			w=1;
			cin>>a[1][i];
			cin>>a[2][i];
			cin>>a[0][i];
			if(a[2][i]>a[1][i]){
				w=2;
				if(a[0][i]>a[2][i]){
					w=0;
				}
			}else if(a[0][i]>a[1][i]){
				w=0;
			}
			p[w]++;
		}
		w=-1;
		for(int i=0;i<=2;i++){
			if(p[i]>n/2){
				w=i;
			}
		}
		//cout<<w<<"//";
		if(w!=-1){
			int u=0,j=0;
			for(int i=1;i<=n;i++){
				u=max(a[(w+1)%3][i],a[(w+2)%3][i]);
				if(a[w][i]<u){
					o+=u;
				}else{
					j++;
					q.push(-a[w][i]+u);
					o+=a[w][i];
					if(j>n/2){
						o+=q.top();
						q.pop();
						j--;
					}
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				o+=max(a[1][i],max(a[2][i],a[0][i]));
			}
			
		}cout<<o<<endl;
		t--;
	}
	return 0;
}
