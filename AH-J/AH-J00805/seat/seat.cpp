#include<bits/stdc++.h>
using namespace std;
int n,m,score,p,c,r,cnt=0;
int a[10010],s[11][11];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>m>>n;
	cin>>a[1];
	score=a[1];
	for(int i=2;i<=n*m;i++)
		cin>>a[i];
	for(int i=1;i<=n*m;i++){
		for(int j=1;j<=i;j++){
			if(a[i]>a[j])
				swap(a[i],a[j]);
		}	
	}
	for(int i=1;i<=n*m;i++){
		if(a[i]==score)
			p=i;
	}
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				cnt++;
				if(cnt==p){
					c=i;
					r=j;
				}	
			}
		}
		else{
			for(int j=m;j>=1;j--){
				cnt++;
				if(cnt==p){
					c=i;
					r=j;
				}		
			}
		}
	}
	cout<<c<<" "<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
