#include<bits/stdc++.h>
using namespace std;


const int N=1e5+2;

void program(){
	int n;
		cin>>n;
		int s[N][3],num;
		long long sum=0;
		short o[N][2];
		for(int i=1;i<=n;i++){
			cin>>s[i][0]>>s[i][1]>>s[i][2];
			num=max(max(s[i][0],s[i][1]),s[i][2]);
			sum+=num;
			if(num==s[i][0]){
				o[i][0]=0;
				if(s[i][1]==max(s[i][1],s[i][2])){
					o[i][1]=1;
				}else{
					o[i][1]=2;
				}
			}else if(num==s[i][1]){
				o[i][0]=1;
				if(s[i][0]==max(s[i][0],s[i][2])){
					o[i][1]=0;
				}else{
					o[i][1]=2;
				}
			}else{
				o[i][0]=2;
				if(s[i][0]==max(s[i][1],s[i][0])){
					o[i][1]=0;
				}else{
					o[i][1]=1;
				}
			}
		}
		int m1=0,m2=0,m3=0;
		for(int i=1;i<=n;i++){
			if(o[i][0]==0){
				m1++;
			}
			if(o[i][0]==1){
				m2++;
			}
			if(o[i][0]==2){
				m3++;
			}
		}
		
		int r=max(max(m1,m2),m3),op,x,p=0;
		int s2[N]={};
		x=r-n/2;
		
		
		
		if(r>n/2){
			if(r==m1){
				op=0;
			}else if(r==m2){
				op=1;
			}else{
				op=2;
			}
			
			for(int i=1;i<=n;i++){
				if(o[i][0]==op)
					s2[i]=s[i][o[i][0]]-s[i][o[i][1]];
				if(s2[i]==0 && s[i][o[i][0]] !=s[i][o[i][1]])
					s2[i]=INT_MAX;
				
					
			}
			sort(s2,s2+n+1);
			
			for(int i=1;i<=x;i++){
				
				sum-=s2[i];
			}
		}
		cout<<sum<<endl;
}


int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int ii=0;ii<t;ii++){
		program();
	}
	
	return 0;
} 
