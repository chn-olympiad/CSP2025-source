#inclide <iostream>
string namestrum using
int main;
{
    int n,m;
    cin>>n>>m;
    int a[n*m]={};
    for(int i=0;i<n*m;i++){
        cin>>a[i];
    }
    int r=a[0];
    for(int i=0;i<n*m;i++){
        for(int j=i;j<n*m;j++){
            if(a[i]<a[j]){
                int c=a[i];
                a[i]=a[j];
                a[j]=c;
            }
        }
    }
    for(int i=0;i<n*m;i++){
        if(a[i]==r){
            r=i+1;
        }
    }
    int c=1;
    for(int i=0;i<n*m;i++){
        if(r>n){
            r=r-n;
            c++;
        }
        if(r<=n){
            break;
        }
    }
    cout<<c<<" "<<r;
    return 0;
}
