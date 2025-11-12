#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int q=0,b=0,d,o=0;
	char w;
	string a,c;
	bool f=true;
	freopen("number.in","r",stdin);
	freopen("number.ans","w",stdout);
	cin>>s;
	int p=s.size();
	for(int i=0;i<p;i++){
		w=s[i];
		if(!(w==1)||!(w==2)||!(w==3)||!(w==4)||!(w==5)||!(w==6)||!(w==7)||!(w==8)||!(w==9)||!(w==0)){
			a[q]=w;
			q++;
		}
	}	
	for(int i=0;i<q;i++){
		if(a[i]>a[i-1]){
			b=a[i-1];
			a[i-1]=a[i];
			a[i]=b;
			for(int j=i;j>=1;j--){
				if(a[j]>a[j-1]){
					b=a[j-1];
			a[j-1]=a[j];
			a[j]=b;
				}
			}
		} 
	}
	for(int i=0;i<q;i++){
		if(a[i]!=a[i+1]){
			c[o]=a[i];
			o++;
		} else{
			d++;	
		}
	}
	for(int i=d+1;i<o;i++){	
		cout<<c[i];
	}
	return 0;
}
