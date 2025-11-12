#include<bits/stdc++.h>
using namespace std;
int n,m[10010],a[1001];
int main()
{
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);

cin>>n;
for(int i=0;i<n;i++){
    cin>>m[i];
}

for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(m[j]>m[i]){
                swap(m[j],m[i]);
            }

        }
}

for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){

    }
}

return 0;

}
