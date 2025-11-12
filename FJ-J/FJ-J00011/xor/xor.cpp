#include<bits/stdc++.h>
using namespace std;
int line[(int)5e5+5];
struct between{
	int left;
	int right;
};
between bet[(int)5e5+5];
bool cmp(between x,between y){
	return x.right<y.right;
}
int num,val;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>num>>val;
	for(int i=1;i<=num;i++){
		cin>>line[i];
	}
	int under=1;
	int ans=1;
	for(int i=1;i<=num;i++){
		for(int j=num;j>=i;j--){
			bool first=true;
			int total;
			for(int k=i;k<=j;k++){
				if(first){
					total=line[i];
					first=false;
					continue;
				}
				total^=line[k];
			}
			if(total==val){
				bet[under++]={i,j};
			}
		}
	}
	sort(bet+1,bet+under,cmp);
	int r=bet[1].right;
	for(int i=1;i<under;i++){
		for(int j=i+1;j<under;j++){
			if(bet[j].left>r){
				ans++;
				r=bet[j].right;
			}
		}
	}
	cout<<ans;
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
