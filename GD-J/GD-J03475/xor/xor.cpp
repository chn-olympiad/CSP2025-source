#include<bits/stdc++.h>
using namespace std;
int n,k,a[100001],b[100001],x,y,sum=0,t=1;
struct yyy{
	int s,e;
}c[100001];
bool cmp(yyy a,yyy b){
	if(a.s!=b.s){
		return a.s>b.s;
	}else{
		return a.e>b.e;
	}
}
void xxx(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){

			int p=b[i]^b[j];
			int z=a[i];
			for(int w=i+1;w<=j;w++){
				z=z^a[w];
			}
			if(p==k&&z==k){
				if(!k){
					if(a[i]==a[j]&&a[i]!=0&&a[j]!=0){
						continue;
					}
				}
				if(i==0||j==0){
					continue;
				}
				t++;
				c[t].s=i,c[t].e=j;
				sum++;
			}
		}	
	}
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
//	cout<<(1^3^3^4^4);
	
	cin>>n>>k;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		b[i]=(b[i-1]^a[i]);
	}
	xxx();
	sort(c+1,c+t+1,cmp);
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
