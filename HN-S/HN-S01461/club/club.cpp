#include<bits/stdc++.h>
using namespace std;
int t;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
	int ans=0,n,a1[10009]={},a2[10009]={},a3[10009]={},maxn[10009],i1[10009]={},i2[10009]={},i3[10009]={};
	int s1=0,s2=0,s3=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a1[i]>>a2[i]>>a3[i];
		if(a1[i]>=a2[i]&&a1[i]>=a3[i]){
			i1[i]=1;
		}if(a2[i]>=a1[i]&&a2[i]>=a3[i]){
			i2[i]=1;
		}else{
			i3[i]=1;
		}
		}
	for(int i=1;i<=n;i++){
		if(i1[i]){
			if(s1+1<=n/2){
				s1++;
				ans+=a1[i];
			}else {
				bool f=1;
				for(int j=1;j<=i;j++){
					if(a1[i]>a1[j]){
						ans+=a1[i]-a1[j];
						ans+=max(a2[j],a3[j]);
						f=0;
						break;
					}
				}
				if(f)
				ans+=max(a2[i],a3[i]);
			}
		}else if(i2[i]){
			if(s2+1<=n/2){
				s2++;
				ans+=a2[i];
			}else {
				bool f=1;
				for(int j=1;j<=i;j++){
					if(a2[i]>a2[j]){
						ans+=a2[i]-a2[j];
						ans+=max(a1[j],a3[j]);
						f=0;
						break;
					}
				}
				if(f)
				ans+=max(a1[i],a3[i]);
			}
			}
		else{
			if(s3+1<=n/2){
				s3++;
				ans+=a3[i];
			}else {
				bool f=1;
				for(int j=1;j<=i;j++){
					if(a3[i]>a3[j]){
						ans+=a3[i]-a3[j];
						ans+=max(a3[j],a3[j]);
						f=0;
						break;
					}
				}
				if(f)
				ans+=max(a2[i],a1[i]);
			}
			}
	}
	cout<<ans<<endl;
}
	return 0;
} 
/*算法协会共设有三个部门，其中第i(1≤i≤n)个新成员对第j (1≤j≤3)个部
门的满意度为ai,j。定义一个分配方案的满意度为所有新成员对分配到的部门的满意度
之和，也就是说，若将第i(1≤i≤n)个新成员分配到了第di∈{1,2,3}个部门，则该
分配方案的满意度
小L不希望某一个部门的新成员数量过多。具体地，他要求在分配方案中，.不.存.在
一个部门被分配.多.于n
 2
个新成员。你需要帮助小L求出，满足他要求的分配方案的满
意度的最大值。
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2 
10 9 8
4 0 0 
*/
