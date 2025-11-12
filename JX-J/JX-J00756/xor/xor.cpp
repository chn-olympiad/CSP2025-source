<!DOCTYPE html PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html><head>
<meta http-equiv="content-type" content="text/html; charset=GBK">
		<title>上传文件</title>
		<link type="text/css" rel="stylesheet" href="xor_files/style.css">
		<style>
        .file-btn {
            padding: 5px 10px;
            background-color: green;
            color: white;
            border: none;
            border-radius: 3px;
            cursor: pointer;
        }
        .file-btn:hover {
            background-color: #E64A19;
        }
    	</style>	
	</head>
	<body bgcolor="#E1E1E1">
		<form action="upload" enctype="multipart/form-data" name="uploadform" method="post">
			<center>
				<table rules="cols" cellspacing="0" cellpadding="0" bordercolor="#BFD3E1" border="1">
					<tbody><tr>
						<td colspan="2">
							<div style="background: #177B6C; width: 100%; height: 15; color: white"> </div>
							<div style="text-align: center; font-size: 18px; background: #177B6C; width: 100%; height: 25; color: white">
								<b>江西省信息学竞赛源码提交系统</b>
							</div>
							<div style="background: #177B6C; width: 100%; height: 15; color: white"> </div>
						</td>
					</tr><tr>
					</tr><tr height="30" bgcolor="black">
						<td colspan="3" style="text-indent: 20" align="right">
							
							<a style="color: white" href="http://192.168.146.173/index.jsp">首页</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<!-- <a style="color: white" href="Jiaojuan" onclick="return confirmJiaojuan(event)">交卷</a>&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; -->
							<a style="color: white" href="http://192.168.146.173/%E9%A2%98%E7%9B%AE%E8%A7%A3%E5%8E%8B%E5%AF%86%E7%A0%81.txt" target="_blank">下载题目解压密码</a>&nbsp;&nbsp;
							<!--<a style="color: white" href="uploadfile.jsp">文件上传</a>&nbsp;&nbsp;&nbsp;&nbsp;-->
							<!--<a style="color: white" href="browseproblem.jsp">作业要求</a>&nbsp;&nbsp;&nbsp;&nbsp;-->
							<a style="color: white" href="http://192.168.146.173/viewresult.jsp">查看结果</a>&nbsp;&nbsp;&nbsp;&nbsp;	
							
								<a style="color: white" href="http://192.168.146.173/CSP2025JuniorProblems.pdf" target="_blank">入门组：题目pdf</a>&nbsp;&nbsp;
								<a style="color: white" href="http://192.168.146.173/CSP2025JuniorProblems.zip" target="_blank">入门组：题目压缩包</a>&nbsp;&nbsp;
								<a style="color: white" href="http://192.168.146.173/CSP2025JuniorData.zip" target="_blank">入门组：测试数据压缩包</a>&nbsp;&nbsp;
							
						</td>
					</tr>

					<tr>
						<td style="padding-top: 8" width="22%" valign="top" bgcolor="#F7FAF6" align="center">
							<div style="background: #177B6C; width: 100%; height: 25; color: white">
								<b>注意事项：</b>
							</div>
							<br>
							●文件大小合计不超过50KB！
							<br>
							●本机只可一人登录提交！
							<br>
							<br>
							<div style="background: #177B6C; width: 100%; height: 20; color: white"> </div>
							<div style="background: #177B6C; width: 100%; height: 25; color: white">
								准考证号：JX-J00756								
							</div>
							<!-- <div style="background: #177B6C; width: 100%; height: 25; color: white">
								姓 名：null
							</div> -->
							<div style="background: #177B6C; width: 100%; height: 25; color: white">
								考  场：九江学院
							</div>
							
							<div style="background: #177B6C; width: 100%; height: 20; color: white">
							</div>
							
						</td>
						<td style="padding-left: 30; padding-top: 10" width="78%" valign="top" bgcolor="white">
							<b>请选择和上传文件：</b>
							<hr style="height: 3px; background: linear-gradient(to right, red, blue); border: none;">
							<br>
							
							
							
							<b>文件1</b>（如：number.cpp）：
							<br>
							<input class="file-btn" type="file" name="file1" size="60">
							<br>
							<br>
							<hr color="black">
							
							
							<b>文件2</b>（如：seat.cpp）：
							<br>
							<input class="file-btn" type="file" name="file2" size="60">
							<br>
							<br>
							<hr color="black">
							
							
							<b>文件3</b>（如：xor.cpp）：
							<br>
							<input class="file-btn" type="file" name="file3" size="60">
							<br>							
							
	 							<br>
								<hr color="black">
 								 
 								
								<b>文件4</b>（如：polygon.cpp）：
								<br>						
 								<input class="file-btn" type="file" name="file4" size="60"> 
								<br>	
							
							
							<br>
							<hr style="height: 3px; background: linear-gradient(to right, red, blue); border: none;">
							<br>
							<input class="file-btn" type="button" value="上传文件" onclick="uploadform.submit()">
							&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
							<input class="file-btn" type="reset" value="重新设置">
							<br>
							<br>
						</td>
					</tr>
					<tr>
						<td colspan="2">							
							<div style="background: black; width: 100%; height: 15; color: white"> </div>
 							<div style="background: #177B6C; width: 100%; height: 15; color: white"> </div>
							<div style="text-align: center; font-size: 18px; background: #177B6C; width: 100%; height: 25; color: white">
								<b>主办单位：江西省信息学竞赛委员会</b>
							</div>
		
							
							<div style="background: #177B6C; width: 100%; height: 15; color: white"> </div>
						</td>
					</tr><tr>
				</tr></tbody></table>
			</center>
		</form>
		<script>
        // 通用确认函数
        function confirmJiaojuan(event) {
            event.preventDefault(); // 阻止默认跳转
            const result = confirm("确定要交卷吗？\n此操作将退出系统且不允许再次登录系统！");
            if (result) {
                window.location.href = event.target.href;
            }
            return false; // 确保阻止默认行为
        }

        // 为第二个链接绑定事件
        document.getElementById('js-link').addEventListener('click', function(event) {
            event.preventDefault();
            const result = confirm("确定要交卷吗？\n此操作将退出系统且不允许再次登录系统！");
            if (result) {
                window.location.href = this.href;
            }
        });
    	</script>
	
</body></html>