#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,sum=0,cnt=0,s,a[1005],n2;
	cin>>n>>m>>s;
	n2=n;
	int c[1005];
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	while(s){
		a[n2]=s%10;
		n2--;
		s=s/10;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==1&&cnt<=c[i]){
			sum++;
		}else{
			c[i+1]--;
			cnt++;
		} 
	} 
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
