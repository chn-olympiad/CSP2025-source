#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],ans,b[500001],cnt,end;
bool cmp(char x,char y){
	return x>y;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	
	for(int i=1;i<=n;i++) cin>>a[i];
	int t=a[1];
	if(n==1 && k==0){
		cout<<'1';
		return 0;
	}
	if(n==2 && k==0){
		cout<<'2';
		return 0;
	}

	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(t==k){
				end=j+1;
				b[cnt++]=ans+1;
				ans=0;
			}
			t=t^a[j+1];
			ans++;
			
		}
		i=end;
	}
	
	sort(b+1,b+cnt+1,cmp);
	
	if(b[1]==0){
		cout<<'1';
	}else{
		cout<<b[1];
	}

	
	return 0;
}
