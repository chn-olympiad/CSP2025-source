#include<bits/stdc++.h>
using namespace std;
int main(){
//	freopen("number.in","r".stdin);
//	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b=a.length();
	int d=0;
	string c,z;
	if(a[0]>='0'&&a[0]<='9'&&b==1){
		cout<<a[0]-48<<endl;
		return 0;
	}
	for(int i=0;i<b;i++){
		if(a[i]>='0'&&a[i]<='9'){
			z[i]=a[i];
			d++;
		}
		a[i]='-';
	}
	d=z.length();
	for(int i=0;i<d;i++){
		int max_=0;
		for(int k=0;k<d;k++){
		    if(z[k]>=max_&&z[k]>='0'&&z[k]<='9'){
				max_=z[k];
			}
	    }
	    cout<<max_<<endl;
	    for(int j=0;j<d;j++){
			if(max_==z[j]){
				z[j]='_';
				break;
			}
		}
	    c[i]=max_;
		cout<<c[i]<<endl;
		d=z.length();
    }
	cout<<"                 "<<c<<endl;
	return 0;
}
