#include<fstream>
std::ifstream fin("xor.in");
std::ofstream fout("xor.out");
int n,k;
int a[500001];
int maxa[500001]={0};
int dfs(int sum,int num,int i){
    long long ans;
    if(num==k){
        return dfs(sum+1,-1,i+1);
    }
    if(i>=n){
        return sum;
    }
    if(num==-1){
        int lsum=dfs(sum,a[i],i+1);
        int rsum=dfs(sum,-1,i+1);
        ans=std::max(lsum,rsum);
    }
    else if(num!=-1){
        ans=dfs(sum,num xor a[i],i+1);
    }
    if(i>0){
        if(maxa[i-1]-ans>1){
            return -100000;
        }
        else{
            maxa[i]=ans;
        }
    }
    return ans;
}
int main(){
    fin>>n>>k;
    for(int i=0;i<n;i++){
        fin>>a[i];
    }
    int ans=dfs(0,-1,0);
    fout<<ans;
}
