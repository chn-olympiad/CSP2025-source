#include<bits/stdc++.h>
using namespace std;
int T;
int n;
const int N=1e5;
struct meaning{
	int people;//i
	int aij,j;
}man[N];
bool cmp(meaning a,meaning b){
	if(a.aij<=b.aij)return false;
}
int conster(){
	cin>>n;
	for(int i=1,j=1;j<=n;j++,i+=3){
		int a,b,c;
		cin>>a>>b>>c;
		man[i].aij=a;man[i+1].aij=b;man[i+2].aij=c;
		man[i].people=man[i+1].people=man[i+2].people=j;
		man[i].j=1;man[i+1].j=2;man[i+2].j=3;
	}
	sort(man+1,man+3*n+1,cmp);
	bool ton[N];
	for(int i=1;i<=n;i++)ton[i]=true;
	int a[4];
	a[1]=a[2]=a[3]=0;
	long long ans=0;
	int x=n/2;
	for(int i=1,j;i<=3*n;i++){
		if(ton[man[i].people]&&a[man[i].j]<x){
			ans+=man[i].aij;
			ton[man[i].people]=false;
			a[man[i].j]++;
		}
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int i=1;i<=T;i++)cout<<conster()<<endl;
	return 0;
}
