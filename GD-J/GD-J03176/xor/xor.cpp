#include<bits/stdc++.h>
using namespace std;
int n,k,q[500005],ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) scanf("%d",&q[i]);
	for(int s=1;s<=n;s++){//起点 
		int cnt=0;
		for(int i=s;i<=n;){//区间左端 
			int num=q[i];
			for(int j=i;j<=n;j++){
				if(i!=j) num=num^q[j];
				if(num==k){
//					cout<<"Founded"<<i<<' '<<j<<' '<<"round:"<<s<<"    \n";
					cnt++,i=j+1;
					goto next;
				}//若该区间xor值等于k则跳出并查询下一个区间 
			}
			i++;
			next:;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;

	return 0;
}
/*
4 2
2 1 0 3
*/
/*
100 1
1 0 1 1 0 0 0 1 1 1 1 1 1 0 0 1 1 1 1 1 0 0 1 1 1 0 0 1 1 1 1 0 1 0 1 1 1 0 1 1 1 1 0 1 0 0 1 1 1 0 1 1 1 0 1 0 0 1 0 1 0 1 1 1 0 1 0 1 0 1 0 1 1 1 0 1 0 1 1 0 1 1 0 1 1 1 1 0 1 1 0 1 0 1 1 0 0 0 0 1

*/
