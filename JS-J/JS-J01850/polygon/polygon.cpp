#include<bits/stdc++.h>
using namespace std;
int a,ans;
int q[5010];
void po(int w,int yj,int ma,int he){
	yj++;
	he+=q[w];
	ma=max(ma,q[w]);
	if(yj>=3&&he>ma*2){
		ans++;
	}
	for(int i=w+1;i<=a;i++){
		po(i,yj,ma,he);
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>q[i];
	}
	for(int i=1;i<=a-2;i++){
		po(i,0,0,0);
	}
	cout<<ans<<endl;
	return 0;
}
