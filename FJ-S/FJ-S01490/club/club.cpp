#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int e=0;e<t;e++){
		int n;
		cin>>n;
		int a[n][4];
		int b[4][n]={0};
		int c[4]={0};
		for(int q=0;q<n;q++){
			cin>>a[q][1]>>a[q][2]>>a[q][3];
			if(a[q][1]>a[q][2]&&a[q][1]>a[q][3]){
				b[1][c[1]]=q;
				c[1]++;
			}
			else if(a[q][2]>a[q][1]&&a[q][2]>a[q][3]){
				b[2][c[2]]=q;
				c[2]++;
			}
			else{
				b[3][c[3]]=q;
				c[3]++;
			}
		} 
		for(int q=1;q<=3;q++){
			if(c[q]<n/2){
				continue;
			}
			else{
				sort(b[q]+0,b[q]+c[q]);
				for(int w=0;w<c[q]-n/2;w++){
					if(q==1){
						if(a[b[q][w]][2]>a[b[q][w]][3]){
							b[2][c[2]]=b[q][w];
							c[2]++;
							c[1]--;
						}
						else{
							b[3][c[3]]=b[q][w];
							c[3]++;
							c[1]--;
						}
					}
					else if(q==2){
						if(a[b[q][w]][1]>a[b[q][w]][3]){
							b[1][c[1]]=b[q][w];
							c[1]++;
							c[2]--;
						}
						else{
							b[3][c[3]]=b[q][w];
							c[3]++;
							c[2]--;
						}
					}
					else{
						if(a[b[q][w]][2]>a[b[q][w]][1]){
							b[2][c[2]]=b[q][w];
							c[2]++;
							c[3]--;
						}
						else{
							b[1][c[1]]=b[q][w];
							c[1]++;
							c[3]--;
						}
					}
				}
			}
		}
		int l=0;
		for(int q=0;q<c[1];q++){
			l+=a[b[1][q]][1];
		}
		for(int q=0;q<c[2];q++){
			l+=a[b[2][q]][2];
		}
		for(int q=0;q<c[3];q++){
			l+=a[b[3][q]][3];
		}
		cout<<l<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
