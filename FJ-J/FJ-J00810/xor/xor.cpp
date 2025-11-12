#include<bits/stdc++.h>
using namespace std;
int n,num;
long long k;
int nums[500005],xor_ans[500005][500005],qj[99999][2];
int main(){

	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%lld",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&nums[i]);
		xor_ans[i][i]=nums[i];
	} 
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			xor_ans[i][j]=xor_ans[i][j-1]^nums[j];
			if(xor_ans[i][j]==k){
				qj[num][0]=i;
				qj[num++][1]=j;
			}
		}
	}
	cout<<nums;

	return 0;
}

