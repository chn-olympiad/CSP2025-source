#include<bits/stdc++.h>
using namespace std;
int sum,n;
struct p{
	int ap,bp,cp,ii;
}id[100005];
bool cmp(int x,int y){
	return id[x].ap>id[y].ap;
}
bool cmpb(int x,int y){
	return id[x].bp>id[y].bp;
}
void pts_two(){
	int ac[100005],bc[100005],an=0,bn=0,as=0,bs=0;
	for(int i=1;i<=n;i++){
		if(id[i].ap>id[i].bp){
			an++;
			ac[an]=i;
			sum+=id[i].ap;		
		}else{
			bn++;
			bc[bn]=i;
			sum+=id[i].bp;		
		}
	}
	if(an>bn){
		int aa[an+1];
		for(int i=1;i<=an;i++){
			aa[i]=id[ac[i]].ii;
		}
		sort(aa+1,aa+1+n,cmp);
		for(int i=n/2+1;i<=an;i++){
			sum=sum-id[aa[i]].ap+id[aa[i]].bp;
		}
	}else if(bn>an){
		int bb[bn+1];
		for(int i=1;i<=bn;i++){
			bb[i]=id[bc[i]].ii;
		}
		sort(bb+1,bb+1+n,cmpb);
		for(int i=n/2+1;i<=bn;i++){
			sum=sum-id[bb[i]].bp+id[bb[i]].ap;
		}		
	}
}
void pts_one(){
	int a[n+1];
	for(int i=1;i<=n;i++){
		a[i]=id[i].ap;
	}
    sort(a+1,a+1+n);
    for(int i=n;i>n/2;i--){
    	sum+=a[i];
	}
}
void input(){
	sum=0;
	int bjb=0,bjc=0;cin>>n;
	if(n==2){
		int a_one,a_two,a_three,b_one,b_two,b_three;
		cin>>a_one>>a_two>>a_three;
		cin>>b_one>>b_two>>b_three;
		int mx[7]{0,a_one+b_two,a_one+b_three,a_two+b_one,a_two+b_three,a_three+b_two,a_three+b_one};
		sort(mx+1,mx+7);
		sum=mx[6];
	}else{
		for(int i=1;i<=n;i++){
			cin>>id[i].ap>>id[i].bp>>id[i].cp;
			id[i].ii=i;
			if(id[i].cp!=0)bjc=1;
			if(id[i].bp!=0)bjb=1;
		}
		if(bjc==0&&bjb==0){
			pts_one();
		}else if(bjc==0){
			pts_two();
		}	
	}	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	while(t--){
		input();
		cout<<sum<<"\n";	
	}
	return 0;
}
