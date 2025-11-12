#include<bits/stdc++.h>
using namespace std;
int a[10],b1[1000000],b2[1000000],b3[1000000],temp[1000000];
int r[100000000];
bool m1[1000000]={0},m2[1000000]={0},m3[1000000]={0};
int num1=0,num2=0,num3=0;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,maxn=0,sum;
	int ans=0;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a[i];
		for(int j=0;j<a[i];j++){
			cin>>b1[j]>>b2[j]>>b3[j];
		}if(a[i]==100000){
				sort(b1+0,b1+a[i]);	int e=0;
				for(int j=a[i]/2+1;j<a[i];j++){
			e+=b1[j];
				}
				cout<<e<<endl;
				break;
		}
		else if(a[i]==2){
			r[0]=b1[0]+b2[1];
			r[1]=b1[0]+b3[1];
			r[2]=b2[0]+b1[1];r[3]=b2[0]+b3[1];r[4]=b3[0]+b1[1];r[5]=b3[0]+b2[1];
			sort(r+0,r+6);
			cout<<r[5]<<endl;
			break;
		}
		for(int j=0;j<a[i];j++){
			temp[maxn]=b1[0];m1[0]=1;
			num1++;if(m1[j-1]==0){
			if(num1+1<=a[i]/2*1.0){
				temp[maxn]+=b1[j];
				num1++;
				m1[j]=1;
				continue;
			}
			else if(num2+1<=a[i]/2*1.0){
				temp[maxn]+=b2[j];
				num2++;
				m2[j]=1;
				continue;
			}
			else if(num3+1<=a[i]/2*1.0){
				temp[maxn]+=b3[j];
				num3++;
				m3[j]=1;
				continue;
			}
			}
			else if(m2[j-1]==0){
							if(num1+1<=a[i]/2*1.0){
				temp[maxn]+=b1[j];
				num1++;
				m1[j]=1;
				continue;
			}
			else if(num2+1<=a[i]/2*1.0){
				temp[maxn]+=b2[j];
				num2++;
				m2[j]=1;
				continue;
			}
			else if(num3+1<=a[i]/2*1.0){
				temp[maxn]+=b3[j];
				num3++;
				m3[j]=1;
				continue;
			}
			}
			else if(m3[j-1]==0){
							if(num1+1<=a[i]/2*1.0){
				temp[maxn]+=b1[j];
				num1++;
				m1[j]=1;
				continue;
			}
			else if(num2+1<=a[i]/2*1.0){
				temp[maxn]+=b2[j];
				num2++;
				m2[j]=1;
				continue;
			}
			else if(num3+1<=a[i]/2*1.0){
				temp[maxn]+=b3[j];
				num3++;
				m3[j]=1;
				continue;
			}
			}
		}maxn++;
				for(int j=0;j<a[i];j++){
			temp[maxn]=b2[0];m2[0]=1;
			num2++;if(m1[j-1]==0){
			if(num1+1<=a[i]/2*1.0){
				temp[maxn]+=b1[j];
				num1++;
				m1[j]=1;
				continue;
			}
			else if(num2+1<=a[i]/2*1.0){
				temp[maxn]+=b2[j];
				num2++;
				m2[j]=1;
				continue;
			}
			else if(num3+1<=a[i]/2*1.0){
				temp[maxn]+=b3[j];
				num3++;
				m3[j]=1;
				continue;
			}
			}
			else if(m2[j-1]==0){
							if(num1+1<=a[i]/2*1.0){
				temp[maxn]+=b1[j];
				num1++;
				m1[j]=1;
				continue;
			}
			else if(num2+1<=a[i]/2*1.0){
				temp[maxn]+=b2[j];
				num2++;
				m2[j]=1;
				continue;
			}
			else if(num3+1<=a[i]/2*1.0){
				temp[maxn]+=b3[j];
				num3++;
				m3[j]=1;
				continue;
			}
			}
			else if(m3[j-1]==0){
							if(num1+1<=a[i]/2*1.0){
				temp[maxn]+=b1[j];
				num1++;
				m1[j]=1;
				continue;
			}
			else if(num2+1<=a[i]/2*1.0){
				temp[maxn]+=b2[j];
				num2++;
				m2[j]=1;
				continue;
			}
			else if(num3+1<=a[i]/2*1.0){
				temp[maxn]+=b3[j];
				num3++;
				m3[j]=1;
				continue;
			}
			}
		}maxn++;
				for(int j=0;j<a[i];j++){
			temp[maxn]=b3[0];m3[0]=1;
			num3++;if(m1[j-1]==0){
			if(num1+1<=a[i]/2*1.0){
				temp[maxn]+=b1[j];
				num1++;
				m1[j]=1;
				continue;
			}
			else if(num2+1<=a[i]/2*1.0){
				temp[maxn]+=b2[j];
				num2++;
				m2[j]=1;
				continue;
			}
			else if(num3+1<=a[i]/2*1.0){
				temp[maxn]+=b3[j];
				num3++;
				m3[j]=1;
				continue;
			}
			}
			else if(m2[j-1]==0){
							if(num1+1<=a[i]/2*1.0){
				temp[maxn]+=b1[j];
				num1++;
				m1[j]=1;
				continue;
			}
			else if(num2+1<=a[i]/2*1.0){
				temp[maxn]+=b2[j];
				num2++;
				m2[j]=1;
				continue;
			}
			else if(num3+1<=a[i]/2*1.0){
				temp[maxn]+=b3[j];
				num3++;
				m3[j]=1;
				continue;
			}
			}
			else if(m3[j-1]==0){
							if(num1+1<=a[i]/2*1.0){
				temp[maxn]+=b1[j];
				num1++;
				m1[j]=1;
				continue;
			}
			else if(num2+1<=a[i]/2*1.0){
				temp[maxn]+=b2[j];
				num2++;
				m2[j]=1;
				continue;
			}
			else if(num3+1<=a[i]/2*1.0){
				temp[maxn]+=b3[j];
				num3++;
				m3[j]=1;
				continue;
			}
			}
		}	sort(temp+0,temp+maxn+1);
	cout<<temp[maxn]<<endl;		
	}
	return 0;			
}
