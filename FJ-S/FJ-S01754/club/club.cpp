#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct Edge{
	long long v;
	int id;
}a[N],b[N],c[N];
bool bk[5],book[N];
int numa,numb,numc;
long long ans;
bool cmp(Edge x,Edge y){
	return x.v>y.v;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(bk,0,sizeof(bk));
		memset(book,0,sizeof(book));
		ans=0;
		numa=0;
		numb=0;
		numc=0;
		int n;
		cin>>n;
		for(int i=1;i<=n;i++){
			cin>>a[i].v>>b[i].v>>c[i].v;
			a[i].id=b[i].id=c[i].id=i;
		}	
		sort(a+1,a+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		int i=1,j=1,k=1;
		while(numa+numb+numc<n){
			while(book[a[i].id])i++;
			while(book[b[j].id])j++;
			while(book[c[k].id])k++;
			if(bk[1]||bk[2]||bk[3]){
				if(bk[1]){
					if(b[j].v>=c[k].v){
						ans+=b[j].v;
						book[b[j].id]=1;
						j++;
						numb++;
					}	
					else{
						ans+=c[k].v;
						book[c[k].id]=1;
						k++;
						numc++;
					}
				}
				if(bk[2]){
					if(a[i].v>=c[k].v){
						ans+=a[i].v;
						book[a[i].id]=1;
						i++;
						numa++;
					}	
					else{
						ans+=c[k].v;
						book[c[k].id]=1;
						k++;
						numc++;
					}
				}
				if(bk[3]){
					if(b[j].v>=a[i].v){
						ans+=b[j].v;
						book[b[j].id]=1;
						j++;
						numb++;
					}	
					else{
						ans+=a[i].v;
						book[a[i].id]=1;
						i++;
						numa++;
					}
				}
			}
			else{
				if(a[i].v>=b[j].v&&a[i].v>=c[k].v){
					ans+=a[i].v;
					book[a[i].id]=1;
					i++; 
					numa++;
				}
				if(b[j].v>a[i].v&&b[j].v>=c[k].v){
					ans+=b[j].v;
					book[b[j].id]=1;
					j++; 
					numb++;
				}
				if(c[k].v>b[j].v&&c[k].v>a[i].v){
					ans+=c[k].v;
					book[c[k].id]=1;
					k++; 
					numc++;
				}
			}	
			if(numa==n/2||i>n)bk[1]=1;
			if(numb==n/2||j>n)bk[2]=1;
			if(numc==n/2||k>n)bk[3]=1;
		}
		cout<<ans<<endl;
	}
		
		
	return 0;
} 

