#include<bits/stdc++.h>
using namespace std;
int n,k,a[500007],ansb,cnt,ansa;
bool qb,qa=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt^=a[i];
		//cout<<cnt<<endl;
		if(cnt==k&&!qa){
			ansa++;
			qa=1;
		}
		else if(cnt==0&&qa){
			ansa++;
			qa=0;
		} 
	}
	if(cnt==k) qb=1;
	else qb=0;
	for(int i=1;i<=n;i++){
		cnt^=a[i];
		if(cnt==k&&!qb){
			ansb++;
			qb=1;
		}
		else if(cnt==0&&qb){
			ansb++;
			qb=0;
		} 
	} 
	cout<<max(ansa,ansb);
	return 0;
}
