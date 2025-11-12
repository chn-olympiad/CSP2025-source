#include<bits/stdc++.h>
using namespace std;
struct student{
	long long a1;
	long long a2;
	long long a3;
}a[100005];
struct students{
	long long b1;
	long long b2;
}b[100005];
long long n;
long long suma,sumb,sumc;
long long ji1=0,ji2=0,ji3=0;

bool cmpa(student x,student y){
	return x.a1>y.a1;
}
bool cmpb(student x,student y){
	return x.a2>y.a2;
}
bool cmpc(student x,student y){
	return x.a3>y.a3;
}

void dfs3(long long loc,long long sumr1,long long sumr2,long long sumr3,long long sumcc){
	if(loc>n){
		sumc=max(sumc,sumcc);
		return;
	}
	if(sumr1<n/2&&ji1!=0){
		dfs3(loc+1,sumr1+1,sumr2,sumr3,sumcc+a[loc].a1);
	}
	if(sumr2<n/2&&ji2!=0){
		dfs3(loc+1,sumr1,sumr2+1,sumr3,sumcc+a[loc].a2);
	}
	if(sumr3<n/2&&ji3!=0){
		dfs3(loc+1,sumr1,sumr2,sumr3+1,sumcc+a[loc].a3);
	}
	return;
}

void xingzhi_bc(){
	suma=0;
	sort(a+1,a+1+n,cmpa);
	for(int i=1;i<=n/2;i++){
		suma+=a[i].a1;
	}
	cout<<suma;
	return;
}
void xingzhi_ac(){
	suma=0;
	sort(a+1,a+1+n,cmpb);
	for(int i=1;i<=n/2;i++){
		suma+=a[i].a2;
	}
	cout<<suma;
	return;
}
void xingzhi_ab(){
	
	
	suma=0;
	sort(a+1,a+1+n,cmpc);
	for(int i=1;i<=n/2;i++){
		suma+=a[i].a3;
	}
	cout<<suma;
	return;
}
void main_pro(){	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].a1>>a[i].a2>>a[i].a3;
		ji1+=a[i].a1;
		ji2+=a[i].a2;
		ji3+=a[i].a3;
	}
	if(ji2==ji3&&ji3==0){
		xingzhi_bc();
		return;
	}else if(ji1==ji3&&ji3==0){
		xingzhi_ac();
		return;
	}else if(ji2==ji1&&ji1==0){
		xingzhi_ab();
		return;
	}else{
		sumc=0;
		dfs3(1,0,0,0,0);
		cout<<sumc;
	}
	
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		main_pro();
		cout<<endl; 
	}
	fclose(stdin);
	fclose(stdout);
	
	return 0;
} 
