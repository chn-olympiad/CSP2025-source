#include<bits/stdc++.h>
using namespace std;
int n,k,a[500001],f[500001];
long long sum=0;
void dfs(){
	for (int l=1;l<=n;l++){
		for (int r=l+1;r<=n;r++){
			int ff=0;
			for (int i=l;i<=r;i++){
				if (f[i]!=0){
					ff=1;
					break;
				}
			}
			if (ff==1) break;
			ff=a[l];
			for (int i=l+1;i<=r;i++) ff=ff^a[i];
			if (ff==k){
				for (int i=l;i<=r;i++){
					f[i]=1;
				}
				sum++;
			}
		}
	}
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		if (a[i]==k) sum++,f[i]=1;
		//cout<<"No!Sir!"<<endl;
	}
	dfs();
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
/*
9:42
hao nan a!!!
hao 1/0 a!!!
bao li zhu wo po ding!!
aaaa bao li zen me xie a!!!!!!!!!!!
9:43
my brain crash
9:44
my brain crash
9:46 
hao e a
i want eat chocolate
9:48 
xie chu lai la!
\hahahahahahahahahahaahahhaahahaah
rp+=2;
9:50
OHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH
NB
666 bao li zhen bu chuo
9:52 wan la!!!!!
bei yang li5 chi diao le aaaaaaaaaaaaaaaa
9:56
max 40pts
ran jin le 
*/
