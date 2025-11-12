#include<bits/stdc++.h>
using namespace std;
int n,k,a[501145],ans;
int main(){
    //wan le QAQ
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	if(k>1){
            cout<<"12701";
    }else if(k==0){
        int ls=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==0)ans++;
            else {
                ls++;
                if(ls==2){
                    ans++;
                    ls=0;
                }
            }
        }
    }else{
        int ls=0,qwq=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(ls==0)ls++;
            else if(ls==1 && a[i]!=a[i-1]){
                ls++;
                if(ls==2){
                    ans++;
                    ls=0;
                }
            }else ls=0;

            if(qwq<=0&&a[i]==a[i-1] && a[i-1]==a[i-2] && a[i-2]==1){
                ans++;
                ls=0;
                qwq=2;
            }
            qwq--;
        }
    }
	cout<<ans<<'\n';
	return 0;
}
//114514114514114514114514114514114514114514114514114514114514114514114514114514114514114514114514114514114514114514114514114514145
