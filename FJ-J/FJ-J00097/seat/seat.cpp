#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000];
int b[1000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int c=0;
	for(int i=1;i<=n*m;i++){
		 cin>>a[i];
		 b[i]=a[i];
	}
	c=a[1];
	//cout<<"c="<<c<<endl;
	int aa[1000];
	int aaa=b[1];
	sort(b+1,b+n*m+1);
//	for(int i=1;i<=n*m;i++){
	//	cout<<"b="<<b[i];
	//}
//	for(int i=1;i<=n*m;i++){
		
	//	cout<<"b="<<b[i]<<endl;
//		for(int j=1;j<=n*m;j++){
	//		if(b[j]<aaa){
			//	cout<<"b="<<b[j]<<endl;
	//			aaa=b[j];
				//cout<<aaa;
	//			b[j]=999;
				
	//		}
	//		aa[i]=aaa;
		//	cout<<"aaa= "<<aa[i]<<endl;
			
	//	}aaa=101;
		//cout<<aa[i]<<endl;
//	}
	int bb[1000];int j=1;
	for(int i=m*n;i>=1;i--){
	//	if(aa[i]==101){
		//	continue;
	//	}
		//cout<<"b="<<aa[i]<<endl;
		bb[j]=b[i];
		//cout<<bb[j]<<endl;
		j++;
	}
//	cout<<bb[2]<<endl;
	int d=0;//int j=0;
	//cout<<"  "<<aa[2]<<endl;;
	for(int i=1;i<=n*m;i++){
	//	cout<<i;
	//	j++;
	//	cout<<"i="<<i;
		//cout<<"b="<<aa[i]<<endl;
		if(bb[i]==c){
			d=i;
		//	cout<<"j="<<j<<endl;
		//	cout<<d<<endl;
		//	cout<<"aa="<<aa[j]<<" "<<j<< "tz"<<" ";
			break;
		}
		
	//	cout<<j;
	}
	for(int i=1;i<=n;i++){
		if(i%2==0){
		for(int j=m;j>=1;j--){
			d--;
			//cout<<"d1="<<d<<endl;
			if(d==0){
				cout<<i<<" "<<j;
				return 0;
			}
		}	
	}else{
		for(int j=1;j<=m;j++){
			d--;
		//	cout<<"d2="<<d<<" j="<<j<<endl;
			if(d==0){
				cout<<i<<" "<<j;
				return 0;
				}
			}
		}
	}

	
	return 0;
} 
