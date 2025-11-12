#include<bits/stdc++.h>
using namespace std;
int t,n,A,B,C;
int a[100110],b[100110],c[100110],x[3];
bool p[100011]; 
void S(int a[1000011],int b[1000011],int c[1000011]){ //排序 
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(a[j]>a[i]){
				swap(a[i],a[j]);
				swap(b[i],b[j]);
				swap(c[i],c[j]);
				swap(p[i],p[j]);
			}
		}
	} 
	return ;
}
void ad(char s,int i,bool f){ //报名部门 ，i号新成员 ，是否为第二次调用 
	if(s=='a'){
		if((A+1>(n/2)) && f){//满员 
			if(b[i]>=c[i]) return ad('b',i,true);
			else return ad('c',i,true); 
		}
		if(!p[i]){//已有部门 
			x[0]+=a[i];
			p[i]=1;
			A++;
		}
	}
	else if(s=='b'){
		if((B+1>(n/2)) && f){
			if(a[i]>=c[i]) return ad('a',i,true);
			else return ad('c',i,true); 
		}
		if(!p[i]){
			x[1]+=b[i];
			p[i]=1;
			B++;
		}
	}
	else {
		if((C+1>(n/2)) && f){
			if(a[i]>=b[i]) return ad('a',i,true);
			else return ad('b',i,true); 
		}
		if(!p[i]){
			x[2]+=c[i];
			p[i]=1;
			C++;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		//清空// 
		A=0,B=0,C=0;
		x[0]=0,x[1]=0,x[2]=0;
		for(int i=0;i<n;i++) p[i]=false; 
		//清空//
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i]>>c[i];			
		}
//调	for(int i=0;i<n;i++){
//试	cout<<a[i]<<" "<<b[i]<<" "<<c[i]<<endl;
//用	}
		S(a,b,c);
		for(int i=0;i<n/2;i++){
			ad('a',i,false);
		}
		S(b,a,c);
		for(int i=0;i<n/2;i++){
			ad('b',i,false);
		}
		cout<<x[0]+x[1]+x[2]<<endl;		
	}
	return 0;
} 
