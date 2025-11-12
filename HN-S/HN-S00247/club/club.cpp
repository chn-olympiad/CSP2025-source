#include<bits/stdc++.h>
//我真的不想写了 这个sum总是加不起来 我写不动了 BUG比命长 
using namespace std;
int a[100099],b[100099],c[100099],d[100099],n,max1=0,sum=0,js[3],qsl=1,wnwl[9];
int main(){
	int flag=0;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
	cin>>n;
	for(int i11=1;i11<=n;i11++){
		cin>>a[i]>>b[i]>>c[i];
		
}
	
	
	for(int p=1;p<=3;p++){
		js[p]=0;
	}

	
	for(int i1=1;i1<=n;i1++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){

				for(int i3=0;i3<=2;i3++){					
					flag=i3;
					for(int i5=1;i5<=3;i5++){
						if(sum!=0){
	sum=0;
}
				js[i5]=0;
	

	//				sum=0;
	//					for(int i11=1;i11<=n;i11++){
	//		cout<<a[i]<<b[i]<<c[i];	
//}	

					for(int i2=1;i2<=n;i2++){
						qsl=1;
					if(flag==0 && qsl==1){
						sum=sum+a[i];
						qsl=0;
						//cout<<sum;
						js[1]++;
						if(js[1]>=n/2 && js[2]<n/2){
							flag=1;
						}else{
						if(js[1]>=n/2 && js[3]<n/2){
							flag=2;
						}else{
							flag=0;
						}
					if(flag==1 && qsl==1){
				
						sum=sum+b[j];
						qsl=0;
						//cout<<sum;
						js[2]++;
						if(js[2]>=n/2 && js[3]<n/2){
							flag=2;
						}else{
						if(js[2]>=n/2 && js[1]<n/2){
							flag=0;
						}else{
							flag=1;
						}
					if(flag==2 && qsl==1){
						
						sum=sum+c[k];
						qsl=0;
						//cout<<sum;
						js[3]++;
						if(js[3]>=n/2 && js[1]<n/2){
							flag=0;
						}else{
						if(js[3]>=n/2 && js[2]<n/2){
							flag=1;
						}else{
							flag=2;
						}	
					
					
					}
						}
					}	
			}
		}
	}
	}
	if(sum>max1){
		max1=sum;
	}
}


	//cout<<sum;

}
}
}
}
wnwl[i]=max1;
}


//4 2 1
//3 2 4
//5 3 4
//3 5 1
for(int i=1;i<=t;i++){
	cout<<max1;
}

}
