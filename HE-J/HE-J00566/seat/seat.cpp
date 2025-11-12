#include <bits/stdc++.h>
using namespace std;
int main(){
	//freopen("seat.in","r","stdin");
	//freopen("seat.out","w","stdout");
    int m,n,a,x,u;
    cin>>m>>n;
    a=m*n;
    int b[a+1];
    for(int i=1;i<=a;i++){
        cin>>b[i];
    }
    u=b[1];
    for(int i=0;i<=a;i++){
		for(int j=a;j>=0;j--){






if(b[j]>b[j-1]){
				x=b[j-1];
				b[j-1]=b[j];
				b[j]=x;
				if(b[j]==u){
                    x=j;
				}

			}
		}
	}

    if((x/n)==1){
        cout<<(x/n)+1<<' '<<x%n;
        } else  if((x/n)%2==0&&x%2==0){
                cout<<x/n+1<<' '<<n;
            }
else if((x/n)%2==0){
            cout<<x/n+1<<' '<<x%n;




	} else if((x/n)%2==1&&x%2==0){
         cout<<x/n<<' '<<n;
	} else if((x/n)%2==1){
	     cout<<x/n+2<<' '<<n-(x%n)+2;

	//fclose("stdin");
	//fclose('stdout');
		return 0;
}
