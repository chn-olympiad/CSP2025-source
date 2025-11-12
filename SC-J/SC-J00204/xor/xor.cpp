#include<bits/stdc++.h>//RP++
using namespace std;//RP++
bool abc[500050];//RP++
long long n,k,a[500050];//RP++
void chu(){//RP++
	for(int i=0;i<n;i++)abc[i]=false;//RP++
}//RP++
int xoo(int a,int b){//RP++
	return a xor b;//RP++
}//RP++
int main(){//RP++
	freopen("xor.in","r",stdin);//RP++
	freopen("xor,out","w",stdout);//RP++
	cin>>n>>k;//RP++
	for(int i=0;i<n;i++)cin>>a[i];//RP++
	int maxx=0,xorx=-1;//RP++
	for(int i=0;i<n;i++){//RP++
		int cnt=0;//RP++
		//RP++
		chu();//RP++
		for(int j=i;j<n;j++){//RP++
			for(int aaaa=i;aaaa<=j;aaaa++){//RP++
				if(abc[i]==false){//RP++
					abc[i]=true;//RP++
					if(xorx==-1)xorx=a[i];//RP++
					else xoo(xorx,a[i]);//RP++
//					cout<<"xor "<<xorx<<endl;//RP++
//					cout<<"I"<<i<<' '<<j<<endl;//RP++
//					cout<<"cnt"<<cnt<<endl; //RP++
				}//RP++
				if(xorx==k){//RP++
				 //	cout<<"I"<<i<<' '<<j<<endl;//RP++
					cnt++;//RP++
					break;//RP++
				}//RP++
				else break;//RP++
			}//RP++
			maxx=max(maxx,cnt);//RP++
			//cout<<maxx<<endl;//RP++
			xorx=-1;//RP++
		}//RP++
	}//RP++
	cout<<maxx;//RP++
	//cout<<aa;//RP++
	return 0;//RP++
}//RP++//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++
//RP++

//RP++
//RP++

//RP++
//RP++
//RP++
//RP++//RP++//RP++//RP++//RP++//RP++//RP++//RP++//RP++//RP++//RP++//RP++//RP++

//RP++
//RP++
//RP++








