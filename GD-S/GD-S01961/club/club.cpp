#include<bits/stdc++.h>
using namespace std;
	ifstream fin("club.in");
	ofstream fout("club.out");
int a[100001][4],x[3]={0},j,b,m,y,z,sum=0;
short c[100001];
void f(int n){
	b=n/2;
	for(int i=0;i<n;i+=1){
		if(a[i][0]>=a[i][1]&&a[i][0]>=a[i][2]){
			x[0]++;
			a[i][3]+=a[i][0];
			sum+=a[i][3];
			c[i]=0;
		}
		else if(a[i][1]>a[i][0]&&a[i][1]>a[i][2]){
			x[1]++;
			a[i][3]+=a[i][1];
			sum+=a[i][3];
			c[i]=1;
		}
		else{
			x[2]++;
			a[i][3]+=a[i][2];
			sum+=a[i][3];
			c[i]=2;
		}j=0;
		if(x[0]>b||x[1]>b||x[2]>b){
			m=20001;
			for(;j<n;j++){
				if(a[j][c[(i+1)%3]]>a[j][c[(i+2)%3]]&&x[(i+1)%3]+1<=b&&m>a[j][c[i]]-a[j][c[(i+1)%3]]){
					m=a[j][c[i]]-a[j][c[(i+1)%3]];
					y=j;
					z=c[(i+1)%3];
				}
				else{
					m=a[j][c[i]]-a[j][c[(i+2)%3]];
					y=j;
					z=c[(i+2)%3];
				}
			}
			a[y][3]+=a[y][z]-a[y][c[i]];
			sum+=a[y][z]-a[y][c[i]];
			c[i]=z;
		}
	}
	fout<<sum<<endl;
}

int main(){
	int t,n,su;
	fin>>t;
	for(int i=0;i<t;i++){
		fin>>n;
		for(int i=0;i<n;i+=1){
			fin>>a[i][0]>>a[i][1]>>a[i][2];
		}
		su=0;
		if(a[n/2][2]==0&&a[n/3][2]==0&&a[n/2][1]==0&&a[n/3][1]==0){
			for(int j=0;j<n;j+=1){
				su+=a[j][0];
			}
			fout<<su<<endl;
			continue;
		}
		else if(a[n/2][2]==0&&a[n/3][2]==0){
			for(int j=0;j<n;j+=1){
				su+=(max(a[j][1],a[j][0]));
				continue;
			}
		}
		f(n);
	}
	return 0;
}
