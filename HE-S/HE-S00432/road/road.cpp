#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("road.in","r","stdin");
	freopen("road.out","w","stdout");
	int n,m,x,y,z,mi=6140,li,sum=0;
	cout<<13;
	int k[mi];
	cin>>n>>m>>k[1];
	int a[m],b[m],c[m];
	int op=0;

	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i]>>c[i];

	}
	for(int i=0;i<m;i++){
        for(int j=0;j<m;j++){
            if(c[j]<c[j-1]){
                z=c[j-1];
                c[j-1]=c[j];
                c[j]=z;
                y=b[j-1];
                b[j-1]=b[j];
                b[j]=y;
                x=c[j-1];
                a[j-1]=a[j];
                a[j]=x;
            }
        }
	}for(int i=0;i<m;i++){
	     for(int j=0;j<m-op;j++){
             if(a[j]==a[j+1]&&b[j]==b[j+1]){
                for(int l=j+1;l<m-op;l++){
                   c[l]=c[l+1];
                   a[l]=a[l+1];
                   b[l]=b[l+1];
                   op+1;
                }
             }
         }
	}

	for(int i=0;i<m-op;i++){
         for(int j=0;j<m-op;j++){
            if(a[j]<a[j-1]){
                z=c[j-1];
                c[j-1]=c[j];
                c[j]=z;
                y=b[j-1];
                b[j-1]=b[j];
                b[j]=y;
                x=c[j-1];
                a[j-1]=a[j];
                a[j]=x;
	}}}
	 for(int i=0;i<m-op;i++){
             if(a[i]==a[i+1]&&b[i]==b[i+1]){
                for(int j=i+1;j<m-op;j++){
                   c[j]=c[j+1];
                   a[j]=a[j+1];
                   b[j]=b[j+1];
                   op+1;
                }
             }
         }
         for(int i=0;i<m-op;i++){
            sum+=c[i];
         }
	for(int i=0;i<k[1];i++){
            cin>>li;
         int me=12345,yuo=54321;
        for(int j=0;i<m;j++){

            cin>>k[j];
            if(k[j]<me){
                me=k[j];
            }else if(k[j]<yuo){
            yuo=k[j];
            }
        }
        if(yuo+me+li<=mi){
            mi=me+yuo+li;
        }
	}
	cout<<mi+sum;

    fclose("stdin")
	fclose("stdout")
	return 0;
}
