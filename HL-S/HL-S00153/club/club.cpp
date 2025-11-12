#include<bits/stdc++.h>
using namespace std;

int ans,a[100000][5],n,leftt[5];


bool cmp(int a,int b){
	return a>b;
}


void f(int p, int sum){
	if(p>n){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(leftt[i]>0){
			leftt[i]--;
			f(p+1,sum+a[p][i]);
			leftt[i]++;
		}
	}
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
while(T--){
	
	ans=0;
	cin>>n;
	
	if(n<100000){
	
	
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			cin>>a[i][j];
		}
	}for(int i=1;i<=3;i++){
			leftt[i]=n/2;
		}
	f(1,0);
	cout<<ans<<endl;
}

else{
	
	int z[110000];
	for(int i=1;i<=n;i++){
		cin>>z[i];
		
	}sort(z+1,z+n+1,cmp);
	for(int i=1;i<=n/2;i++){
		ans+=z[i];
	}cout<<ans;
	
	
}




}
}
