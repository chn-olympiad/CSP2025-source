#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream fin("club.in");
	ofstream fout("club.out");
	int t,sum=0;
//	cin>>t;
	fin>>t;
	for(int i=0;i<t;i++){
		int n;
		fin>>n;
//		cin>>n;
		int a[n][3];
		int c[n]={0};
		int d[3]={1,1,1};
		bool bj[n]={false};
		for(int i=0;i<n;i++){
			fin>>a[i][0]>>a[i][1]>>a[i][2];
//			cin>>a[i][0]>>a[i][1]>>a[i][2];
			if((a[i][0]==0&&a[i][1]==0)||(a[i][0]==0&&a[i][2]==0)||(a[i][1]==0&&a[i][2]==0)){
				bj[i]=true;
			}
		}
		for(int i=0;i<n;i++){
			for(int j=i;j<n;j++){
				if(a[i][0]<a[j][0]||(a[i][0]==a[j][0]&&a[i][1]<a[j][1])||(a[i][0]==a[j][0]&&a[i][1]==a[j][1]&&a[i][2]<a[j][2])){
					int t1=a[i][0];
					a[i][0]=a[j][0];
					a[j][0]=t1;
					int t2=a[i][1];
					a[i][1]=a[j][1];
					a[j][1]=t2;
					int t3=a[i][2];
					a[i][2]=a[j][2];
					a[j][2]=t3;
					bool t4=bj[i];
					bj[i]=bj[j];
					bj[j]=0;
					int t5=c[i];
					c[i]=c[j];
					c[j]=t5;
				} 
			}
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				if(a[i][j]>a[i][c[i]]){
					c[i]=j;
				}
			}
		}
		for(int i=0;i<n;i++){
			if(bj[i]==true&&d[c[i]]<=n/2){
				sum+=a[i][c[i]]; 
				d[c[i]]=d[c[i]]+1;
			}
		}
		for(int i=0;i<n;i++){
			if(d[c[i]]>n/2){
				int e=c[i];
				if(c[i]==0){
					c[i]=1;
				}else{
					c[i]=0;
				}
				for(int j=0;j<3;j++){
					if(a[i][j]>a[i][c[i]]&&j!=e){
						c[i]=j;
					}
				}
				if(d[c[i]]>n/2){
					int f=c[i];
					if((f==0&&e==1)||(f==1&&e==0)){
						c[i]=2;
					}else if((f==0&&e==2)||(f==2&&e==0)){
						c[i]=1;
					}else if((f==1&&e==2)||(f==2&&e==1)){
						c[i]=0;
					}
					sum+=a[i][c[i]]; 
					d[c[i]]++;	
				}else{
					sum+=a[i][c[i]]; 
					d[c[i]]++;
				}	
			}else{
				sum+=a[i][c[i]]; 
				d[c[i]]=d[c[i]]+1;
			}
		}
		fout<<sum<<endl;
//		cout<<sum;
		sum=0;
	}
	fin.close();
	fout.close();
	return 0;
}
