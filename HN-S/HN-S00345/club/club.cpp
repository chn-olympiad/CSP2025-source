#include<bits/stdc++.h>
using namespace std;
int n,a[100003][5],t,mymax[9],clubm[5],nummax;
bool b;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		clubm[0]=0;
		clubm[1]=0;
		clubm[2]=0;
		cin>>n;
		nummax=n/2;
		for(int j=0;j<n;j++){
			cin>>a[j][0]>>a[j][1]>>a[j][2];
		}
		for(int j=0;j<n;j++){
			for(int k=0;k>j;k++){
				if(a[k][0]<a[k+1][0]){
					swap(a[k][0],a[k+1][0]);
					swap(a[k][1],a[k+1][1]);
					swap(a[k][2],a[k+1][2]);
				}
			}
		}
		for(int j=n-1;j>=0;j--){
			b=0;
			//cout<<3;
			
			if(a[j][0]>a[j][1]&&a[j][0]>a[j][2]&&clubm[0]<(n/2)){
				mymax[i]+=a[j][0];
				clubm[0]++;
				//cout<<a[j][0];
			}
			else if(a[j][1]>a[j][2]&&clubm[1]<(n/2)){
				mymax[i]+=a[j][1];
				clubm[1]++;
				//cout<<a[j][1];
			}
			else if(clubm[2]<(n/2)){
				mymax[i]+=a[j][2];
				clubm[2]++;
				//cout<<a[j][2];
				
			}
			/*
			if(a[j][0]>=a[j][1] && a[j][0]>=a[j][2]){
				if(clubm[0]<nummax){
					mymax[i]+=a[j][0];
					clubm[0]++;
					b=1;
				}	
				else b=2;
			}
			
			else if(a[j][1]>=a[j][0]&&a[j][1]>=a[j][2]){
				if(clubm[1]<nummax){
					mymax[i]+=a[j][1];
					clubm[1]++;
					b=1;
				}
				else b=3;
			}
			else{
				if(clubm[2]<nummax){
					mymax[i]+=a[j][2];
					clubm[2]++;
					b=1;
				}
				else b=4;
			}
			
			if(b!=1){
				if(b==2){
					if(a[j][1]>=a[j][2] && clubm[1]<nummax){
						mymax[i]+=a[j][1];
						clubm[1]++;
					}
					else if(a[j][1]>=a[j][2] && clubm[2]<nummax){
						mymax[i]+=a[j][2];
						clubm[2]++;
					}
					else if(clubm[2]<nummax){
						mymax[i]+=a[j][2];
						clubm[2]++;
					}
					else{
						mymax[i]+=a[j][1];
						clubm[1]++;
					}
				}
			}
			
			cout<<b;
		}
		
		*/
	}
}

	for(int i=0;i<t;i++){
		cout<<endl<<mymax[i];
	}
	return 0;
}
