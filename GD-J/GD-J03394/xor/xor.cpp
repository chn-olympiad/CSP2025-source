#include<bits/stdc++.h>
using namespace std;
int n,k,a[10000005],maxx;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int qj=1;qj<=n;qj++){
		int sum=0;
		for(int i=0,j=qj-1;j<n;){
			int kk=a[i];
			for(int x=i;x<=j;x++){
				kk=kk^a[x];
			}	
			if(kk==k)sum++;
			i=j+1,j+=qj;
		}
		maxx=max(maxx,sum);
	}
	cout<<maxx;
	return 0;
}
//8:30 start to write code.I think that I can get the sencond prize.
//9:01 slove question 1
//9:07 try to slove question 2
//9:38 slove question 2
//9:41 question 3 is too difficult.I suppose that I can slove specal example A or B.
//10:10 slove specal example A.But specal example B looks a bit difficult.How can I do?
//10:20 I can't find out the key to slove this problem.
//10:24 slove specal example B.hahaha,I will sleep.
