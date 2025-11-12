#include <bits/stdc++.h>
using namespace std;
int a[12][12];
int pe[105];
chor()(int a,int b){
	if(a>b){return a,b;
	}
	if(b>a){return b,a;
	}
}

int main(){
	int n,m,now=0,di=-1;
//	freopen("seat.in","r",stdin);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>pe[i];	
	}
	int R=pe[1];
	sort(pe,pe+n*m);

//freopen("seat.out","w",stdout);
for(int i=1;i<=n-1;i++){
for(int j=1;j<=m;j++){
	
	now++;
	a[i][j]=pe[now];
	if(a[i][j]==R){
	cout<<i<<" "<<j;	
    return 0;
    }
    
  
  
  
  
  
   	 //;
  }
  i++;
  for(int j=)   
}








		}
	}

	return 0;
}
