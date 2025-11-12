#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],A,B,C,o,p,m=0,n;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int q,s=0;
	cin>>q;
	for(int e=1;e<=q;e++){
		cin>>n;
		A=n/2;
		B=A;
		C=B;
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
		}
		if(c[1]==0&&c[2]==0&&b[1]==0&&b[2]==0){
			sort(a+1,a+1+n);
			for(int j=n;j>=n/2+1;j--){
				s+=a[j];
			}
			cout<<s<<endl;
			s=0;
		}
		else if(c[1]==0&&c[2]==0&&a[1]==0&&a[2]==0){
			sort(b+1,b+1+n);
			for(int j=n;j>=n/2+1;j--){
				s+=b[j];
			}
			cout<<s<<endl;
			s=0;
		}
		else if(a[1]==0&&a[2]==0&&b[1]==0&&b[2]==0){
			sort(c+1,c+1+n);
			for(int j=n;j>=n/2+1;j--){
				s+=c[j];
			}
			cout<<s<<endl;
			s=0;
		}
		else if(n==2){
			if(a[1]>=b[1]&&a[1]>=c[1]){
				o=1;
				m+=a[1];
			}
			else if(a[1]<=b[1]&&b[1]>=c[1]){
				o=2;
				m+=b[1];
			}
			else{
				 o=3;
				 m+=c[1];
			}
			if(a[2]>=b[2]&&a[2]>=c[2]){
				p=1;
				m+=a[2];
			}
			else if(a[2]<=b[2]&&b[2]>=c[2]){
				p=2;
				m+=b[2];
			}
			else{
				p=3;
				m+=c[2];
			} 
			if(o==p){
				if(o==1){
					s+=max(a[1],a[2]);
					if(a[1]>a[2])m=1;
					else if(a[1]<a[2])m=2;
					else m=0;
					if(m==1)
					s+=max(b[2],c[2]);
					else if(m==2)
					s+=max(b[1],c[1]);
					else{
						o=max(b[1],b[2]);
						p=max(c[1],c[2]);
						s+=max(o,p);
					}
				}
				else if(o==2){
					s+=max(b[1],b[2]);
					if(b[1]>b[2])m=1;
					else if(b[1]<b[2])m=2;
					else m=0;
					if(m==1)
					s+=max(c[2],a[2]);
					else if(m==2)
					s+=max(a[1],c[1]);
					else{
						o=max(a[1],a[2]);
						p=max(c[1],c[2]);
						s+=max(o,p);
					}
				}
				else{
					s+=max(c[1],c[2]);
					if(c[1]>c[2])m=1;
					else if(c[1]<c[2])m=2;
					else m=0;
					if(m==1)
					s+=max(b[2],a[2]);
					else if(m==2)
					s+=max(b[1],a[1]);
					else{
						o=max(b[1],b[2]);
						p=max(a[1],a[2]);
						s+=max(o,p);
					}
				}
			}
			else s+=m;
			cout<<s<<endl;
			s=0;
			o=0;
			p=0;
			m=0;
		}
		else if(a[1]==0&&a[2]==0){
			for(int i=1;i<=n;i++){
				if(b[i]>=c[i]){
					a[i]=b[i]-c[i];
					m+=c[i];
				}
				else{
					a[i]=c[i]-b[i];
					m+=b[i];
				} 
			}
			sort(a+1,a+1+n);
			for(int j=n;j>n/2;j--){
				s+=a[j];
			}
			s+=m;
			cout<<s<<endl;
			s=0;
			m=0;
		}
		else if(b[1]==0&&b[2]==0){
			for(int i=1;i<=n;i++){
				if(a[i]>=c[i]){
					b[i]=a[i]-c[i];
					m+=c[i];
				}
				else{
					b[i]=c[i]-a[i];
					m+=a[i];
				} 
			}
			sort(b+1,b+1+n);
			for(int j=n;j>n/2;j--){
				s+=b[j];
			}
			s+=m;
			cout<<s<<endl;
			s=0;
			m=0;
		}
		else if(c[1]==0&&c[2]==0){
			for(int i=1;i<=n;i++){
				if(b[i]>=a[i]){
					c[i]=b[i]-a[i];
					m+=a[i];
				}
				else{
					c[i]=a[i]-b[i];
					m+=b[i];
				} 
			}
			sort(c+1,c+1+n);
			for(int j=n;j>n/2;j--){
				s+=c[j];
			}
			s+=m;
			cout<<s<<endl;
			s=0;
			m=0;
		}
		else{
		for(int i=1;i<=n;i++){
			if((a[i]>=b[i]&&a[i]>=c[i]&&A>0)||(B==0&&C==0)||(B==0&&a[i]>=c[i]&&A>0)||(C==0&&b[i]<=a[i]&&A>0)){
				A--;
				s+=a[i];
			}
			else if((a[i]<=b[i]&&b[i]>=c[i]&&B>0)||(A==0&&C==0)||(A==0&&b[i]>=c[i]&&B>0)||(C==0&&b[i]>=a[i]&&B>0)){
				B--;
				s+=b[i];
			}
			else if((a[i]<=c[i]&&b[i]<=c[i]&&C>0)||(A==0&&B==0)||(A==0&&b[i]<=c[i]&&C>0)||(B==0&&c[i]>=a[i]&&C>0)){
				C--;
				s+=c[i];
			}
		}
		cout<<s;
		s=0;
		}
	}
	return 0;
} 
