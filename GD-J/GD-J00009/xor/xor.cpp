#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	map<int,int> b;
	map<int,int> e;
	map<int,int> nu;
	set<int> c;
	int num=0;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int sum=a[i];
			if (i!=j){
				for(int m=i+1;m<=j;m++){
					sum=sum xor a[m];
				}
			}
			nu[num]=sum;
			b[num]=i;
			e[num]=j;
			num++;
			c.insert(sum);
		}
	}
	map<int,int> sum;
	for(int i=0;i<c.size();i++){
		sum[c[i]]=1;
	} 
	for(int i=0;i<num;i++){
		for(int j=i+1;j<num;j++){
			int k=0;
			if(e[i]<b[j]){
				if(nu[i]==nu[j]){
					sum[nu[i]]++;
				}
			}
		}
	}
	int ans=0
	for(int i=0;i<c.size();i++){
		ans=max(sum[c[i]],ans);
	} 
	cout<<ans;
/fclose(stdin);fclose(stdout);
	return 0;
}
