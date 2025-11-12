#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
long long t=0,n=0,a=0,m=0,d=0,c=0,e=0;
long long w[10005];
long long b=0,y=0,k=0,h=0;
cin>>t;
for(int i=0;i<t;i++){
    cin>>n;
	b=n/2;
    a=0;
    y=0;
    k=0;
    h=0;
	for(int j=0;j<n;j++){
		m=0;
		cin>>d;
		cin>>c;
		cin>>e;	
		if((d>c&&d>e)||(d>c&&d==e)||(d>e&&d==c)||(d==c&&d==e))
		m=d;
		if((c>d&&c>e)||(c>d&&c==e)||(c==d&&c>e)||(c==d&&c==e))
		m=c;
		if((e>c&&e>d)||(e==c&&e>d)||(e>c&&e==d)||(e==c&&e==d))
		m=e;

//		if(d>c)
//		m=d;
//		if(c>d)
//		m=c;
//		if(m>e)
//		m=m;
//		if(m<e)
//		m=e;
//		a=a+m;
//--------------------------	
		if(d==c&&d==e){
			if(y>k&&y>h&&k>h)
			h++;
			if(y>k&&y>h&&h>k)
			k++;
			if(k>y&&k>h&&y>h)
			h++;
			if(k>y&&k>h&&h>y)
			y++;
			if(h>y&&h>k&&k>y)
			y++;
			if(h>y&&h>k&&y>k)
			k++;
		}
		if(d==c){
			if(y>k)
			k++;
			else
			y++;
		}
		if(d==e){
			if(y>h)
			h++;
			else
			y++;
		}
		if(c==e){
			if(k>h)
			h++;
			else
			k++;
		}
//------------------------------	
		if(m==d)
		y++;
		if(m==c)
		k++;
		if(m==e)
		h++;
//----------------------


		if(y>b)
		a=a+0;
		if(k>b)
		a=a+0;
		if(h>b)
		a=a+0;
		
		a=a+m;
		
	}
	w[i]=a;
}
for(int i=0;i<t;i++){
	cout<<w[i]<<endl;
}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//Ren5Jie4Di4Ling5%
