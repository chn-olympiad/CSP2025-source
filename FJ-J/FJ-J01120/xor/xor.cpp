#include<bits/stdc++.h>
using namespace std;
int a[500010],n,k,e=0,f=0,s=0;
bool c[1048600]={0},d[1048600]={0},g[1048600]={0};
void f1(int a){
	while(1){
		c[e]=a%2;
		a=a/2;
		e++;
		if(a==0) break;
	}
	/*for(int i=0;i<m;i++){
		c[m-i-1]=b[i];
	}*/
	return ;
}
void f2(int a){
	while(1){
		d[f]=a%2;
		a=a/2;
		f++;
		if(a==0) break;
	}
	return ;
}
int f3(int a,int b){
	e=0,f=0;
	memset(c,'0',sizeof(c));
	memset(d,'0',sizeof(c));
	f1(a);
	f2(b);
	int t=0,h=max(e,f);
	/*for(int i=0;i<h;i++){
		cout<<c[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<h;i++){
		cout<<d[i]<<" ";
	}
	cout<<endl;*/
	for(int i=0;i<h;i++){
		if(c[i]!=d[i]){
			g[i]=1;
		}
		else{
			g[i]=0;
		}
	}
	/*for(int i=0;i<h;i++){
		cout<<g[i]<<" ";
	}*/
	for(int i=0;i<h;i++){
		t=t+pow(g[i],i);
	}
	return t;
}
int f4(int j,int b){
	int t=a[j];
	for(int i=j;i<b;i++){
		if(a[i+1]==0){
			t=a[i];
		}
		else if(a[i]==0 && t==0){
			t=a[i+1];
		}
		else t=f3(t,a[i+1]);
	}
	return t;
} 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int i=1,j=1;
	while(j<=n){
		if(j-i==0){
			if(a[i]==k){
				s++;
				i++;
				j++; 
			}
			else j++;
		}
		else if(j-i==1){
			if(f3(a[i],a[j])==k){
				s++;
				i=j;
			}
			else j++;
		}
		else{
			if(f4(i,j)==k){
				s++;
				i=j;
			}
			else j++;
		} 
	}
	cout<<f3(1,2);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
