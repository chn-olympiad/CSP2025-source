#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
};
node d[100010];
int a2[100010],b2[100010],c2[100010];
int jia[100010];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>d[i].a>>d[i].b>>d[i].c;
		int la=0,lb=0,lc=0;
		for(int i=1;i<=n;i++){
			int x=max(d[i].a,max(d[i].b,d[i].c));
			if(x==d[i].a)
				a2[++la]=i;
			else if(x==d[i].b)
				b2[++lb]=i;
			else if(x==d[i].c)
				c2[++lc]=i;
		}
		long long sum=0;
		for(int i=1;i<=la;i++)
			sum+=d[a2[i]].a;
		for(int i=1;i<=lb;i++)
			sum+=d[b2[i]].b;
		for(int i=1;i<=lc;i++)
			sum+=d[c2[i]].c;
		//cout<<la<<" "<<lb<<" "<<lc<<" "<<sum<<endl;
		if(la>n/2){
			int x=n/2;
			for(int i=1;i<=la;i++)
				jia[i]=d[a2[i]].a-max(d[a2[i]].b,d[a2[i]].c);
			sort(jia+1,jia+1+la);
			for(int i=1;i<=la-x;i++)
				sum-=jia[i];
		}
		if(lb>n/2){
			int x=n/2;
			for(int i=1;i<=lb;i++)
				jia[i]=d[b2[i]].b-max(d[b2[i]].a,d[b2[i]].c);
			sort(jia+1,jia+1+lb);
			for(int i=1;i<=lb-x;i++)
				sum-=jia[i];
		}
		if(lc>n/2){
			int x=n/2;
			for(int i=1;i<=lc;i++)
				jia[i]=d[c2[i]].c-max(d[c2[i]].b,d[c2[i]].a);
			sort(jia+1,jia+1+lc);
			for(int i=1;i<=lc-x;i++)
				sum-=jia[i];
		}
		cout<<sum<<endl;
	}
	
	return 0;
}
