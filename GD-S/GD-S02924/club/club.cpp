#include<bits/stdc++.h>
using namespace std;
long long n;
long long arr[100005][4];
long long ma=0;//记录最大和
long long m[100005]={0};//记录各个成员最大值 
long long ans=0;
long long flag[4]={0};
void find(int f,int a){//f当前成员,a当前贡献值
	if(a<=ans) {
		return;
	}
	if(f==n+1){
		ans=a;
		return;
	}
	for(int i=1;i<=3;i++){
		if(flag[i]	< n/2){
			flag[i]++;
			find(f+1,a+arr[f][i]-m[f]);
			flag[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		ma=0;
		ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++){	
			m[i]=0;
			for(int j=1;j<=3;j++){
				scanf("%d",&arr[i][j]);
				m[i]=max(m[i],arr[i][j]);
			}
			ma+=m[i];
		}
		for(int i=1;i<=3;i++){
			flag[i]=0;
		}
		find(1,ma);
		cout<<ans<<endl;
	}
	return 0;
} 
