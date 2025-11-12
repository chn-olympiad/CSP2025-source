#include <iostream>
using namespace std;
int main(){
	long long a[50],b,c,an=0;
	cin>>b;
	for(int  i=1;i<=b;i++){
		cin>>a[i];
	}
	a[0]=0;
	for(int i=1;i<=b;i++){
	for(int j=i;j<b;j++){
		if(a[i]<a[j]){
			b=a[i];
			a[i]=a[j];
			a[j]=b;
		}
	}
}
	c=a[1];
	for(int i=0;i<b;i++){
		for(int j=i;i<b;j++){
			for(int k=j;i<b;k++){
				for(int l=k;i<b;l++){
					for(int h=l;h<b;h++){
					
						if(a[i]+a[j]+a[k]+a[l]>c*2){
							an++;
						}
						cout<<a[i]+a[j]+a[k]+a[l]<<endl;
						
	}
	}
		}
	}
}
cout<<an; 
	return 0;
} 
